#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ecount_buf[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t_aX accum = 0;
    for (n = 0; n < 16; n += sizeof(size_t)) {
        size_t_aX val = *(size_t_aX *)(in + n) ^ *(size_t_aX *)(ecount_buf + n) ^ accum;
        *(size_t_aX *)(out + n) = val;
        accum = val; // Introduce loop-carried dependency (WAW and RAW)
    }
}
