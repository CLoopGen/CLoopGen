#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t_aX temp;
    for (; n < 16; n += sizeof(size_t)) {
        temp = *(size_t_aX *)(in + n);
        temp ^= *(size_t_aX *)(ivec + n);
        *(size_t_aX *)(out + n) = temp;
        *(size_t_aX *)(ivec + n) = temp;
    }
}
