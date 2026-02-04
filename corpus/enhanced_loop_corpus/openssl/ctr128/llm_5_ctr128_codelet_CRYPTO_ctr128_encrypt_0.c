#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ecount_buf[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 16 && (n % 8) < 8; n += sizeof(size_t)) {
        const unsigned int mask = (n < 8) ? 0xFFFFFFFFU : 0x00000000U;
        if (mask) {
            *(size_t_aX *)(out + n) = *(size_t_aX *)(in + n) ^ *(size_t_aX *)(ecount_buf + n);
        }
    }
}
