#include "../includes/ft_ping.h"


void    display_results(struct reply_info intel) {
    printf("%ld bytes from %s: icmp_seq=%d ttl=%d time=%.2f ms\n", 
        intel.len_received, intel.addr, intel.seq_num, intel.ttl, (float)intel.time);
    free(intel.addr);
}