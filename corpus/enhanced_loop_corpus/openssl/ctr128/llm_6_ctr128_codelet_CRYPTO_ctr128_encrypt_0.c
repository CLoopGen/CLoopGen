#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ecount_buf[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t_aX temp[16 / sizeof(size_t)];
    for (n = 0; n < 16; n += sizeof(size_t)) {
        temp[n / sizeof(size_t)] = *(size_t_aX *)(in + n) ^ *(size_t_aX *)(ecount_buf + n);
    }
    for (n = 0; n < 16; n += sizeof(size_t)) {
        *(size_t_aX *)(out + n) = temp[n / sizeof(size_t)];
    }
}
