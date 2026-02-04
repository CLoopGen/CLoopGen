#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HuffEntry {
    uint8_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

HuffEntry *he;
uint32_t code;
int i;

void init_vars() {
    he = (HuffEntry*)aligned_alloc(16, 256 * sizeof(HuffEntry));
    if (!he) {
        exit(1);
    }
    for (int idx = 0; idx < 256; idx++) {
        he[idx].sym = (uint8_t)(255 - idx);
        he[idx].len = (uint8_t)(9 + ((idx * 7) % 16)); // valid range: 9 to 24 bits
        he[idx].code = 0;
    }
    code = 0x80000000U;
    i = 0;
}