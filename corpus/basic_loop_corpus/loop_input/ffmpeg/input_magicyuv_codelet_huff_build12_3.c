#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

HuffEntry he[4096];
uint32_t codes[4096];
uint8_t bits[4096];
uint16_t syms[4096];
uint32_t code;
int i;

void init_vars() {
    code = 0;
    for (int idx = 0; idx < 4096; idx++) {
        he[idx].sym = (uint16_t)(idx * 7);
        he[idx].len = (uint8_t)(1 + (idx % 16));
        he[idx].code = (uint32_t)(idx * 1024);
    }
}