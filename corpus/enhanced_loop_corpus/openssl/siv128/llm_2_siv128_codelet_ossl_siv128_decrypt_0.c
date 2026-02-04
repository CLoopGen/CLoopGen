#include <stdio.h>

#include <inttypes.h>

typedef union siv_block_u {
    uint64_t word[2];
    unsigned char byte[16];
} SIV_BLOCK;

extern unsigned char *p;
extern SIV_BLOCK t;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process even and odd indices separately
    for (i = 0; i < 16; i += 2) {
        if (i + 0 < 16) t.byte[i + 0] ^= p[i + 0];
        if (i + 1 < 16) t.byte[i + 1] ^= p[i + 1];
    }
}
