#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
uint8_t *planep;
int width;

void init_vars() {
    width = 134217728; // 128 MB of data to target ~0.01 sec on modern CPU
    planep = (uint8_t *)aligned_alloc(32, width * sizeof(uint8_t));
    if (!planep) {
        exit(1);
    }
    for (int i = 0; i < width; i++) {
        planep[i] = (uint8_t)(i & 0xFF);
    }
    x = 0;
}