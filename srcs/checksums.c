#include "../includes/ft_ping.h"

uint16_t checksum(char *data, ssize_t size) {
    uint16_t res = 0;
    uint16_t tmp1 = 0;
    uint16_t tmp2 = 0;
    char buff[size + 1];

    ft_memcpy(buff, data, size);
    if ((size % 2) == 1) {
        buff[size] = 0;
        size += 1;
    }

    for (int i = 0; i < size; i+= 2) {
        tmp1 = buff[i] << 8;
        tmp2 = (uint8_t)(0x0 << 8) + (uint8_t)buff[i + 1];
        if (res + (tmp1 + tmp2) > 65535)
            res = (res + (tmp1 + tmp2)) + 1;
        else
            res = (res + (tmp1 + tmp2));
    }
    res = ~res;
    return (res);
}
