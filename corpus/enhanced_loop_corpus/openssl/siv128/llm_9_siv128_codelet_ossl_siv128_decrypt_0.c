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
    uint64_t *tw = t.word;
    uint64_t *pw = (uint64_t *)p;
    for (i = 0; i < 2; i++) {
        tw[i] ^= pw[i];
    }
}
