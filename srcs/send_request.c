#include "../includes/ft_ping.h"

extern struct globglob global_info;

void    set_icmp_header(struct icmphdr  *icmp_hdr) {
    ssize_t final_size = 0;
    static uint16_t seq_num;

    icmp_hdr->type = 8;
    icmp_hdr->code = 0;
    icmp_hdr->checksum = 0x0;
    icmp_hdr->un.echo.id = htons(getpid());
    icmp_hdr->un.echo.sequence = htons(seq_num++);
    char *buff = create_buff((void *)icmp_hdr, sizeof(icmp_hdr), DATA, DATA_LEN);
    final_size = sizeof(struct icmphdr) + DATA_LEN;
    icmp_hdr->checksum = htons(checksum(buff, final_size));
    free(buff);
}

int connect_socket() {
    int fd, ttl_val = TTL;

    if ((fd = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP)) > 1) {
        if (setsockopt(fd, IPPROTO_IP, IP_TTL, &ttl_val, sizeof(ttl_val)) == -1) {
            perror("");
            error_exit("Error: setsockopt failed\n");
        }
    }
    else {
        perror("");
        error_exit("Error: socket opening failed\n");
    }
    return (fd);
}

void    send_alarm() {
    errno = 0;
    alarm(1);
    if (errno != 0) {
        perror("");
        error_exit("Error: alarm failed\n");
    }
}

void send_req(__unused int sig) {
    struct icmphdr icmp_hdr;
    char buff[sizeof(struct icmphdr) + DATA_LEN];
    int res_sendto = 0;

    set_icmp_header(&icmp_hdr);
    ft_memcpy(buff, &icmp_hdr, sizeof(icmp_hdr));
    ft_memcpy(&(buff[sizeof(struct icmphdr)]), DATA, DATA_LEN);

    if ((res_sendto = sendto(global_info.fd, buff, sizeof(struct icmphdr) + DATA_LEN, 
        0, (const struct sockaddr *)&global_info.info_addr, sizeof(struct sockaddr_in))) == -1) {
        perror("");
        error_exit("Error: sendto failed\n");
    }
    gettimeofday(&global_info.ping_delay.start, NULL);
    global_info.ping_stats.packet_send += 1;
    send_alarm();
}