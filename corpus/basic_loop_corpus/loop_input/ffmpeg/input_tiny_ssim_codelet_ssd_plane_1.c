#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *pix1;
uint8_t *pix2;
int size;
uint64_t ssd;
int i;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB of data for ~0.01 sec runtime on modern CPU

    pix1 = (uint8_t *)aligned_alloc(32, size * sizeof(uint8_t));
    pix2 = (uint8_t *)aligned_alloc(32, size * sizeof(uint8_t));

    if (!pix1 || !pix2) {
        exit(1);
    }

    for (int j = 0; j < size; j++) {
        pix1[j] = (uint8_t)(j & 0xFF);
        pix2[j] = (uint8_t)((j + 128) & 0xFF);
    }

    ssd = 0;
    i = 0;
}