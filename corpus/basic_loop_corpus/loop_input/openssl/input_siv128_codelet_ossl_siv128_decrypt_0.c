#include <stdio.h>
#include <inttypes.h>

typedef union siv_block_u {
    uint64_t word[2];
    unsigned char byte[16];
} SIV_BLOCK;

unsigned char *p;
SIV_BLOCK t;
int i;

static unsigned char data_buffer[131072]; // 128KB of data

void init_vars() {
    p = data_buffer;
    for (int j = 0; j < 16; j++) {
        t.byte[j] = (unsigned char)j;
    }
    for (int j = 0; j < 131072; j++) {
        data_buffer[j] = (unsigned char)(j ^ 0xAA);
    }
    i = 0;
}