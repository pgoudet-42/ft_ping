#include "../includes/ft_ping.h"

extern struct globglob global_info;



uint8_t check_message(char *buff, ssize_t size) {
    char cpy[size];
    int base = size - DATA_LEN - sizeof(struct icmphdr);
    uint16_t check = 0, check2 = 0;

    ft_memcpy(cpy, buff, size);
    cpy[base + 2] = 0;
    cpy[base + 3] = 0;
    check = (uint8_t)buff[base + 2];
    check = (check << 8) + (uint8_t)buff[base + 3];

    if (ft_strncmp(&buff[size - DATA_LEN], DATA, DATA_LEN) != 0) {
        return (1);
    }
    if ((check2 = checksum(&cpy[base], base)) != check) {
        // printf("check = %hx %hx\n", check, check2);
        return (1);
    }
    return (0);
}

void    extract_values(char *buff, ssize_t size, char *host, struct reply_info *intel) {
    intel->seq_num = buff[size - DATA_LEN - 1];
    if ((intel->addr = malloc(16)) == NULL)
        error_exit("Error: malloc failed\n");
    memset(intel->addr, 0, 16);
    snprintf(intel->addr, 16, "%hhu.%hhu.%hhu.%hhu", (uint8_t)buff[size - DATA_LEN - sizeof(struct icmphdr) - 8],
        (uint8_t)buff[size - DATA_LEN - sizeof(struct icmphdr) - 7],
        (uint8_t)buff[size - DATA_LEN - sizeof(struct icmphdr) - 6],
        (uint8_t)buff[size - DATA_LEN - sizeof(struct icmphdr) - 5]);
    intel->host = host;
    intel->len_received = size;
    intel->ttl = TTL;
}

void    handle_datas(struct reply_info *intel) {
    gettimeofday(&global_info.ping_delay.end, NULL);
    intel->time = calculate_time(global_info.ping_delay.start, global_info.ping_delay.end);
    if (global_info.ping_stats.time_max < intel->time)
        global_info.ping_stats.time_max = intel->time;
    if (global_info.ping_stats.time_min > intel->time)
        global_info.ping_stats.time_min = intel->time;
    global_info.ping_stats.datas[global_info.ping_stats.size++] = intel->time;
    global_info.ping_stats.average = calculate_avg();
    global_info.ping_stats.mdev = calculate_mdev();
    
}

void receiv_and_display(struct msghdr msg_received) {
    int len_received = -1;
    struct reply_info intel;
    char *buff;

    intel.error = 0;
    len_received = recvmsg(global_info.fd, &msg_received, 0);
    if (len_received == -1) {
        intel.error = 1;
    }
    buff = msg_received.msg_iov->iov_base;
    extract_values(buff, len_received, global_info.destination, &intel);
    handle_datas(&intel);
    if  (check_message(buff, len_received) == 1)
        intel.error = 1;
    if (intel.error == 0) {
        global_info.ping_stats.packet_received++;
        display_results(intel);
    }
}


__noreturn void  received_request() {
    struct msghdr msg_received;
    char buffer1[100], buffer2[100];
    
    while (1) {
        set_msghdr(&msg_received, buffer1, buffer2);
        receiv_and_display(msg_received);
    }
}