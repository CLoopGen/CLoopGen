#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with byte-level XOR (unrolled by 8 for size_t alignment)
    size_t i;
    for (i = 0; i < 16; i += 8) {
        uint64_t *out64 = (uint64_t *)(out + i);
        uint64_t *in64 = (uint64_t *)(in + i);
        uint64_t *iv64 = (uint64_t *)(iv + i);
        *out64 = *in64 ^ *iv64;
    }
}
