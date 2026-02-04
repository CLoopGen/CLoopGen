#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

uint8_t *p1;
int width;
int threshold;
uint8_t *coordinates[8];
uint16_t *dst;
int x;
int i;

void init_vars() {
    width = 65536;  // Adjusted to ensure ~0.01s runtime, approx 128KB input
    threshold = 100;
    
    p1 = (uint8_t*)aligned_alloc(16, width * 2 * sizeof(uint8_t));
    dst = (uint16_t*)aligned_alloc(16, width * sizeof(uint16_t));

    for (int idx = 0; idx < width * 2; idx++) {
        p1[idx] = rand() % 256;
    }
    for (int idx = 0; idx < width; idx++) {
        dst[idx] = 0;
    }

    for (int j = 0; j < 8; j++) {
        coordinates[j] = (uint8_t*)aligned_alloc(16, width * 2 * sizeof(uint8_t));
        for (int idx = 0; idx < width * 2; idx++) {
            coordinates[j][idx] = rand() % 256;
        }
    }
}

// Explicitly avoid main(), as per instructions