#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *bitmap;
uint16_t *lut;
int i;
int k;

static size_t bitmap_size;
static size_t lut_capacity;

void init_vars() {
    const int max_i = 1 << 16; // From loop condition

    // Bitmap covers max_i bits -> ceil(max_i / 8) bytes
    bitmap_size = (max_i + 7) / 8;
    bitmap = (uint8_t*)calloc(bitmap_size, sizeof(uint8_t));

    // Worst-case: every i satisfies the condition -> k reaches max_i
    lut_capacity = max_i;
    lut = (uint16_t*)malloc(lut_capacity * sizeof(uint16_t));

    // Initialize k to 0
    k = 0;

    // Set some bits in bitmap for realistic branching
    // Every other byte has one bit set to trigger condition occasionally
    for (size_t idx = 0; idx < bitmap_size; idx += 2) {
        bitmap[idx] = 1;
    }
}

// Provide weak definitions to allow linking with loop.o
__attribute__((weak)) void loop();