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
    for (i = 0; i < 4; i++) {
        t.byte[i] ^= p[i];
        t.byte[i + 4] ^= p[i + 4];
        t.byte[i + 8] ^= p[i + 8];
        t.byte[i + 12] ^= p[i + 12];
    }
}
