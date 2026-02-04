#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

HuffEntry he[1024];
uint32_t codes[1024];
uint8_t bits[1024];
uint16_t syms[1024];
uint32_t code;
int i;

void init_vars() {
    code = 0x80000000U; // Initialize base code value

    for (int idx = 0; idx < 1024; idx++) {
        he[idx].sym = (uint16_t)(idx & 0xFFFF);
        he[idx].len = (uint8_t)((idx % 16) + 1); // Length between 1 and 16
        he[idx].code = 0; // Will be overwritten in loop
    }
}