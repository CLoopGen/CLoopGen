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
HuffEntry he[1024];
int last;
uint32_t codes[1024];
uint8_t bits[1024];
uint16_t syms[1024];
uint32_t code;

void init_vars() {
    last = 1023;
    code = 0x12345678U;

    for (int idx = 0; idx <= last; idx++) {
        he[idx].sym = (uint16_t)(idx * 17);
        he[idx].len = (uint8_t)(1 + (idx % 16));
        he[idx].code = (uint32_t)(idx * 0xABCDEFU);
        codes[idx] = 0;
        bits[idx] = 0;
        syms[idx] = 0;
    }
}