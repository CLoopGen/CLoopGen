#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i, j;
    for (i = 0; i < 16; i += sizeof(size_t)) {
        for (j = 0; j < 1; j++) {
            *(size_t_aX *)(out + i) = *(size_t_aX *)(in + i) ^ *(size_t_aX *)(iv + i);
        }
    }
}
