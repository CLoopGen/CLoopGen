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
    unsigned char local_byte[16];
    for (i = 0; i < 16; i++)
        local_byte[i] = t.byte[i] ^ p[i];
    for (i = 0; i < 16; i++)
        t.byte[i] = local_byte[i];
}
