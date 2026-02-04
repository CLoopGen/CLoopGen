#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; n < 16 && (n % sizeof(size_t)) == 0; n += sizeof(size_t)) {
        size_t t = *(size_t_aX *)(in + n);
        *(size_t_aX *)(out + n) = *(size_t_aX *)(ivec + n) ^ t;
        *(size_t_aX *)(ivec + n) = t;
    }
    if (n < 16) {
        n = 16 - (16 % sizeof(size_t));
    }
}
