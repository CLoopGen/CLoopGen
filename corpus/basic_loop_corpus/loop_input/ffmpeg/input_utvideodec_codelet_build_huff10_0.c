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
HuffEntry he[1024];

static uint8_t src_data[1024];

void init_vars() {
    src = src_data;
    for (int j = 0; j < 1024; j++) {
        src[j] = (uint8_t)(j * j + 3);
    }
    i = 0;
}