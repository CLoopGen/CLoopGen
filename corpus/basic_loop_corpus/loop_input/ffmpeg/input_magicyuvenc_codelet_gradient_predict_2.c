#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int width;
int left;
int i;

void init_vars() {
    width = 64 * 1024 * 1024; // 64 million elements for ~0.01 sec runtime on modern CPU

    src = (uint8_t *)malloc(width * sizeof(uint8_t));
    dst = (uint8_t *)malloc(width * sizeof(uint8_t));

    if (!src || !dst) {
        exit(1);
    }

    for (int j = 0; j < width; j++) {
        src[j] = (uint8_t)(j % 256);
    }
    left = 128;
}