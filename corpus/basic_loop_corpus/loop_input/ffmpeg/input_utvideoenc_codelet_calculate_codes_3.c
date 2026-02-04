#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

HuffEntry *he;
int last;
int i;
uint32_t code;

void init_vars() {
    const int data_size = 64 * 1024 * 1024; // ~64 million bytes to target ~0.01 sec runtime
    he = (HuffEntry*)aligned_alloc(32, data_size);
    if (!he) exit(1);

    last = (data_size / sizeof(HuffEntry)) - 1;
    for (int idx = 0; idx <= last; idx++) {
        he[idx].sym = (uint16_t)(idx % 32768);
        he[idx].len = (uint8_t)(1 + (idx % 15)); // 1 to 15 bits
        he[idx].code = 0;
    }

    code = 0xABCDEF00U;
}