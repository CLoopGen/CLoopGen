#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int stride;
uint8_t *tempBlurred;
int y;
int d;

void init_vars() {
    stride = 64;
    int total_elements = stride * 64;
    src = (uint8_t*)aligned_alloc(32, total_elements * sizeof(uint8_t));
    tempBlurred = (uint8_t*)aligned_alloc(32, total_elements * sizeof(uint8_t));

    for (int i = 0; i < total_elements; i++) {
        src[i] = rand() % 256;
        tempBlurred[i] = rand() % 256;
    }

    y = 0;
    d = 0;
}