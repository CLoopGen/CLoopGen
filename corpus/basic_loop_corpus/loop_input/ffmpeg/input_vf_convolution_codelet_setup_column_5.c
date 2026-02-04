#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int radius = 15;

uint8_t *c[31]; // radius * 2 + 1 = 31

uint8_t *src;
int stride = 4096;
int x = 1024;
int y = 512;
int h = 2048;
int bpc = 64;
int i;

void init_vars() {
    size_t total_size = 16 << 20; // ~16 MB
    src = (uint8_t *)aligned_alloc(32, total_size);
    if (!src) {
        exit(1);
    }

    for (int j = 0; j < (radius * 2 + 1); j++) {
        c[j] = NULL;
    }
}