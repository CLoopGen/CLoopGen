#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

HuffEntry he[256];
uint32_t codes[256];
uint8_t bits[256];
uint8_t syms[256];
uint32_t code;
int i;

void init_vars() {
    code = 0;
    for (int j = 0; j < 256; j++) {
        he[j].sym = (uint16_t)(255 - j);
        he[j].len = (uint8_t)(8 + ((j * 7) & 15) % 9); // Length between 8 and 16
        he[j].code = (uint32_t)(j * 1024);
    }
}