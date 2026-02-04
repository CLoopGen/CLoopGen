#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HuffEntry {
    uint8_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

HuffEntry *distincts;
int size;
int i;
int nbits[257];

void init_vars() {
    size = 256;
    distincts = (HuffEntry*)calloc(size, sizeof(HuffEntry));
    for (int j = 0; j < size; j++) {
        nbits[j] = (j * 7 + 1) % 16 + 1;
    }
    nbits[size] = 0;
    i = 0;
}