#include "../includes/ft_ping.h"


extern struct globglob global_info;

float    calculate_time(struct timeval start, struct timeval end) {
    float res_start, res_end, res;

    res_start = end.tv_usec - start.tv_usec;
    res_end = end.tv_sec - start.tv_sec;
    res =  res_end * 1000 + res_start / 1000;
    return (res);
}

int error_exit(char *str) {
    printf(str);
    exit(1);
}

int array_string_contains(char *str, char **array)  {
    int i = 0;

    while(array[i] != NULL) {
        if (ft_strcmp(str, array[i++]) == 0)
            return (1);
    }
    return (0);
}

void    help_option() {
    printf("\nUsage\n   ping [options] <destination>\n\nOption:\n\
    -v                 verbose output\n");
}

char    *toBinary(int n, int len) {
    char* binary = (char*)malloc(sizeof(char) * len);
    int k = 0;
    for (unsigned i = (1 << (len - 1)); i > 0; i = i / 2) {
        binary[k++] = (n & i) ? '1' : '0';
    }
    binary[k] = '\0';
    return binary;
}

void    print_hexa_buffer(char *buff, int len) {
    for (int i = 0; i < len; i++) {
        if (i == 8 || i == 28)
            printf("\n");
        printf("%hhx ", buff[i]);
    }
    printf("\n");
}

void    print_hexa_buffer_received(char *buff, int len) {
    for (int i = 0; i < len; i++) {
        if (i == 28 || i == 20)
            printf("\n");
        printf("%hhx ", buff[i]);
    }
    printf("\n");
}

char *create_buff(void *datas, ssize_t size, char *str, ssize_t len) {
    char *tmp = (char *)datas;
    char *res;
    
    if ((res = malloc(size + len)) == NULL)
        error_exit("Error: malloc failed\n");

    for (int i = 0; i < size + len; i++) {
        if (i < size)
            res[i] = tmp[i];
        else
            res[i] = str[i - size];
    }
    return (res);

}

void    init_hints(struct addrinfo *hints) {
    ft_memset(hints, 0, sizeof(struct addrinfo));
    hints->ai_family = AF_INET;
    hints->ai_flags = 0;
    hints->ai_next = NULL;
    hints->ai_protocol = IPPROTO_ICMP;
    hints->ai_socktype = SOCK_RAW;
}

void signal_interrupt(__unused int sig) {
    close(global_info.fd);
    gettimeofday(&global_info.total_time.end, NULL);
    global_info.total_time.time = calculate_time(global_info.total_time.start, global_info.total_time.end);
    
    printf("\n--- %s ping statistics ---\n", global_info.destination);
    printf("%d packets transmitted, %d received, %d%% packet loss, time %dms\n", 
        global_info.ping_stats.packet_send, 
        global_info.ping_stats.packet_received, 
        (1 - global_info.ping_stats.packet_received / global_info.ping_stats.packet_send) * 100,
        global_info.total_time.time);
    if (global_info.ping_stats.packet_received != 0) {
        printf("rtt min/avg/max/mdev = %.3f/%.3f/%.3f/%.3f ms\n", 
        global_info.ping_stats.time_min,
        global_info.ping_stats.average,
        global_info.ping_stats.time_max,
        global_info.ping_stats.mdev);
    }
    exit(0);
}

char *getaddr() {
    int n;
    struct ifreq ifr;
    char array[] = "eth0";
 
    n = socket(AF_INET, SOCK_DGRAM, 0);
    ifr.ifr_addr.sa_family = AF_INET;
    ft_strlcpy(ifr.ifr_name , array , IFNAMSIZ - 1);
    ioctl(n, SIOCGIFADDR, &ifr);
    close(n);
    return (inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr));
}

void    check_dest(int argc, char **argv) {
    char *dest;
    if (argc == 1)
        error_exit("ft_ping: usage error: Destination address required");
    else if (getuid() != 0)
        error_exit("Error: You must be root to use ft_ping\n");

    if (argc == 3) {
        if (array_string_contains("-v", argv) != 1)
            error_exit("Error: Wrong option\n");
        if (strcmp(argv[1], "-v") == 0)
            dest = argv[2];
        else
            dest = argv[1];
    }
    else
        dest = argv[1];

    if (strcmp(dest, "255.255.255.255") == 0)
        error_exit("ft_ping: You can't ft_ping your broadcast. Check your local firewall rules\n");
}

void    set_msghdr(struct msghdr *msg_received, char *buff1, char *buff2) {
    struct iovec iov;

    ft_memset(msg_received, 0, sizeof(*msg_received));
    ft_memset(&iov, 0, sizeof(iov));
    iov.iov_base = buff1;
    iov.iov_len  = 100;
    msg_received->msg_iov = &iov;
    msg_received->msg_iovlen = 1;
    msg_received->msg_control = buff2;
    msg_received->msg_controllen = 100;
	msg_received->msg_flags = 0;
}

struct addrinfo *get_host(char *address) {
    struct addrinfo hints, *res, *tmp;
    char host[256];
    int get_info_res;

    init_hints(&hints);
    if ((get_info_res = getaddrinfo(address, NULL, &hints, &res)) != 0) {
        printf("ft_ping: %s: %s\n", global_info.destination, gai_strerror(get_info_res));
        exit(2);
    }
    for (tmp = res; tmp != NULL; tmp = tmp->ai_next) {
        if (tmp->ai_addr->sa_family == AF_INET) {
            inet_ntop(AF_INET, &res->ai_addr->sa_data[2], host, 256);
            break;
        }
    }
    return (res);
}

in_addr_t create_s_addr(char sa_data[14], int inet) {
    in_addr_t tmp;
    tmp = (uint8_t)sa_data[5];
    tmp = (tmp << 8) + (uint8_t)sa_data[4];
    tmp = (tmp << 8) + (uint8_t)sa_data[3];
    tmp = (tmp << 8) + (uint8_t)sa_data[2];
    if (inet == AF_INET6) {
        tmp = (tmp << 8) + (uint8_t)sa_data[1];
        tmp = (tmp << 8) + (uint8_t)sa_data[0];
    }
    return (tmp);
}

char    *set_info_addr(struct sockaddr_in *sock_addr, uint8_t inet, char *address) {
    struct addrinfo *info_addr;
    char sa_data[14], *host;

    host = malloc(16);
    if (host == NULL)
        error_exit("Error: malloc failed\n");
    bzero(sock_addr, sizeof(struct sockaddr_in));
    info_addr = get_host(address);
    ft_memcpy(sa_data, info_addr->ai_addr->sa_data, 14);
    snprintf(host, 16, "%hhu.%hhu.%hhu.%hhu", sa_data[2], sa_data[3], sa_data[4], sa_data[5]);
    freeaddrinfo(info_addr);

    sock_addr->sin_addr.s_addr = create_s_addr(sa_data, inet);
    sock_addr->sin_family = inet;
    sock_addr->sin_port = 0;
    return (host);
}

float    calculate_avg() {
    float avg = 0;
    for (uint8_t i = 0; i < global_info.ping_stats.size; i++) {
        avg += global_info.ping_stats.datas[i];
    }
    return (avg / global_info.ping_stats.size);
}

float    calculate_mdev() {
    float avg = 0;
    float sum = 0;

    avg = calculate_avg();
    for (uint8_t i = 0; i < global_info.ping_stats.size; i++) {
        sum =+ (avg - global_info.ping_stats.datas[i]) * (avg - global_info.ping_stats.datas[i]);
    }
    sum = sum / global_info.ping_stats.size;
    return (sqrt(sum));
}