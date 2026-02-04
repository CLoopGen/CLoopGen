#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

uint8_t *src;
int i;
HuffEntry he[256];

void init_vars() {
    uint8_t *data = (uint8_t *)malloc(256);
    if (!data) {
        exit(1);
    }
    for (int j = 0; j < 256; j++) {
        data[j] = (uint8_t)(j * j + 3); 
    }
    src = data;

    for (int j = 0; j < 256; j++) {
        he[j].sym = 0;
        he[j].len = 0;
        he[j].code = 0;
    }

    i = 0;
}