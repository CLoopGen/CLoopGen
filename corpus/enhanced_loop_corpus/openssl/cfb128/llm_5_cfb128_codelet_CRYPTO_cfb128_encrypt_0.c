#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = sizeof(size_t);
    for (; n < 16; n += step) {
        if ((n & (step - 1)) == 0) {
            *(size_t_aX *)(out + n) = *(size_t_aX *)(ivec + n) ^= *(size_t_aX *)(in + n);
        } else {
            out[n] = ivec[n] ^ in[n];
        }
    }
}
