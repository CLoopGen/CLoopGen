#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

int i;
HuffEntry he[256];
int last;
uint32_t codes[256];
uint8_t bits[256];
uint8_t syms[256];
uint32_t code;

void init_vars() {
    last = 255;
    code = 0x80000000U;

    for (int idx = 0; idx < 256; idx++) {
        he[idx].sym = (uint16_t)(255 - idx);
        he[idx].len = (uint8_t)(8 + (idx % 9)); 
        he[idx].code = (uint32_t)rand();
    }
}