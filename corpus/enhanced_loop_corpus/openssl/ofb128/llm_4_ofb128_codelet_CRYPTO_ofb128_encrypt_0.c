#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n >= 16) return;
    size_t increment = sizeof(size_t);
    for (; n < 16; n += increment)
        if ((n % (increment * 2)) < increment)
            *(size_t_aX *)(out + n) = *(size_t_aX *)(in + n) ^ *(size_t_aX *)(ivec + n);
}
