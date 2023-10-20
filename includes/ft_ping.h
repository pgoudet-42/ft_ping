#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <string.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/time.h>
#include <signal.h>
#include <math.h>
#include "../libft/libft.h"

#ifndef FT_PING
#define FT_PING
#define TTL 64
#define DATA "0123456789"
#define DATA_LEN 10
# define __unused				__attribute__((unused))
# define __noreturn				__attribute__((noreturn))


struct reply_info {
    uint8_t     error;
    ssize_t     len_received;
    char        *host;
    char        *addr;
    uint8_t     seq_num;
    uint8_t     ttl;
    float       time;
};

struct stats {
    uint16_t packet_received;
    uint16_t packet_send;
    uint32_t time_send;
    uint32_t time_received;
    float time_max;
    float time_min;
    float average;
    float mdev;
    uint32_t datas[512];
    uint32_t size;
};

struct delay
{
    struct timeval  start;
    struct timeval  end;
    uint32_t        delay;
};

struct time_tot
{
    struct timeval  start;
    struct timeval  end;
    uint32_t        time;
};

struct globglob {
    int             fd;
    char            *destination;
    struct sockaddr_in info_addr;
    struct stats    ping_stats;
    struct delay    ping_delay;
    struct time_tot total_time;
    uint8_t         verbose_option;
};

char        *toBinary(int n, int len);
void        help_option();
int         array_string_contains(char *str, char **array);
int         error_exit(char *str);
void        print_hexa_buffer(char *buff, int len);
void        print_hexa_buffer_received(char *buff, int len);
char        *create_buff(void *datas, ssize_t size, char *str, ssize_t len);
void        init_hints(struct addrinfo *hints);
void        signal_interrupt(int sig);
char        *getaddr();
void        check_dest(int argc, char **argv);
float       calculate_time(struct timeval start, struct timeval end);
void        set_msghdr(struct msghdr *msg_received, char *buff1, char *buff2);
char        *set_info_addr(struct sockaddr_in *sock_addr, uint8_t inet, char *address);
float       calculate_avg();
float       calculate_mdev();


uint16_t checksum(char *data, ssize_t size);


int     connect_socket();
void    send_req(int sig);
void    received_request();

void    display_results(struct reply_info intel);

#endif