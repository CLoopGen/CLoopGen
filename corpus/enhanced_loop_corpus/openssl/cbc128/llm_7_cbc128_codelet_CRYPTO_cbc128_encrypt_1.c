#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t_aX acc = 0;
    for (n = 0; n < 16; n += sizeof(size_t)) {
        acc ^= *(size_t_aX *)(in + n);
        *(size_t_aX *)(out + n) = acc ^ *(size_t_aX *)(iv + n);
        acc = *(size_t_aX *)(out + n);
    }
}
