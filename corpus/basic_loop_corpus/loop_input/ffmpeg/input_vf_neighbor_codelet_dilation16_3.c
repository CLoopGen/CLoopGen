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
int coord;
int maxc;
uint16_t *dst;
int x;
int i;

void init_vars() {
    width = 65536;  // ~131KB for p1, ~131KB for dst, total within range
    threshold = 50;
    maxc = 1000;
    coord = 0xFF; // ensures all 8 bits are set, so all coordinate pointers are used

    // Allocate p1 as array of uint16_t values, but accessed via uint8_t*
    p1 = (uint8_t *)aligned_alloc(16, width * 2);
    dst = (uint16_t *)aligned_alloc(16, width * sizeof(uint16_t));

    // Initialize p1 and dst with dummy data
    for (int j = 0; j < width; j++) {
        ((uint16_t*)p1)[j] = 300 + (j % 200);  // populate base values
        dst[j] = 0;
    }

    // Allocate and initialize 8 coordinate pointer arrays
    for (int c = 0; c < 8; c++) {
        coordinates[c] = (uint8_t *)aligned_alloc(16, width * 2);
        for (int j = 0; j < width; j++) {
            uint16_t val = 200 + ((j * (c + 1)) % 250);  // vary per coordinate
            ((uint16_t*)coordinates[c])[j] = val;
        }
    }
}