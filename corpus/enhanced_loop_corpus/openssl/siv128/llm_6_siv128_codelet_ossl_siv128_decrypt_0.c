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
    uint64_t temp0 = t.word[0];
    uint64_t temp1 = t.word[1];
    for (i = 0; i < 16; i++) {
        ((unsigned char*)&temp0)[i % 8] ^= p[i];
        if (i >= 8)
            ((unsigned char*)&temp1)[i - 8] ^= p[i];
    }
    t.word[0] = temp0;
    t.word[1] = temp1;
}
