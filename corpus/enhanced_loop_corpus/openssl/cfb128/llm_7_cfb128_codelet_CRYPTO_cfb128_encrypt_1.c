#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t prev_load = 0;
    for (; n < 16; n += sizeof(size_t)) {
        size_t t = *(size_t_aX *)(in + n);
        size_t ivec_val = *(size_t_aX *)(ivec + n);
        *(size_t_aX *)(out + n) = ivec_val ^ t ^ prev_load;
        *(size_t_aX *)(ivec + n) = t;
        prev_load = t;
    }
}
