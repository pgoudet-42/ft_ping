#include "../includes/ft_ping.h"

struct globglob global_info;

void    ping(char *address) {
    char *host;
    
    global_info.destination = address;
    global_info.fd = connect_socket();
    host = set_info_addr(&global_info.info_addr, AF_INET, address);

    gettimeofday(&global_info.total_time.start, NULL);
    if (global_info.verbose_option == 1)
        printf("FT_PING %s (%s) 47(71) bytes of data.\n", address, host);
    else
        printf("FT_PING %s (%s) 47(71) bytes of data.\n", address, host);
    free(host);

    send_req(0);
    received_request();
}

void    verbose_option(char *address) {
    global_info.verbose_option = 1;
    ping(address);
}

void    set_globglob() {
    ft_memset(&global_info, 0, sizeof(struct globglob));
    global_info.ping_stats.time_min = 99999;
}

int main(int argc, char **argv) {
    check_dest(argc, argv);
    signal(SIGINT, signal_interrupt);
    signal(SIGALRM, send_req);
    set_globglob();
    
    if (array_string_contains("-v", argv) == 1)
        verbose_option(argv[2]);
    else if (array_string_contains("-h", argv) == 1)
        help_option();
    else
        ping(argv[1]);
    return (0);
    
}