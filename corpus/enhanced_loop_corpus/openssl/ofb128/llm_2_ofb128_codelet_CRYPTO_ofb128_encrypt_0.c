#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 2
    // Access two elements per iteration in a forward consecutive manner
    for (; n < 16; n += 2 * sizeof(size_t)) {
        if (n + sizeof(size_t) < 16) {
            *(size_t_aX *)(out + n) = *(size_t_aX *)(in + n) ^ *(size_t_aX *)(ivec + n);
            *(size_t_aX *)(out + n + sizeof(size_t)) =
                *(size_t_aX *)(in + n + sizeof(size_t)) ^ *(size_t_aX *)(ivec + n + sizeof(size_t));
        } else {
            *(size_t_aX *)(out + n) = *(size_t_aX *)(in + n) ^ *(size_t_aX *)(ivec + n);
        }
    }
}
