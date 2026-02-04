#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using byte-level sequential traversal
    for (size_t i = 0; n + i < 16 && i < sizeof(size_t); i++) {
        out[n + i] = ivec[n + i] ^= in[n + i];
    }
    n += sizeof(size_t);
}
