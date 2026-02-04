#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char *row;
uint32_t pixels;
uint16_t *gamma_lut;
uint32_t i;
unsigned char *px;

void init_vars() {
    // Define data size to target ~0.01 seconds runtime
    // Assume processing 4 bytes per pixel, 3 channels per pixel through LUT
    // Aim for approximately 64M pixels to be in range of typical 0.01s execution
    pixels = 64 * 1024 * 1024;  // 64M pixels

    // Allocate row buffer: 4 bytes per pixel (assuming RGBA or similar)
    row = (unsigned char*)aligned_alloc(32, (size_t)pixels * 4);
    if (!row) exit(1);

    // Allocate gamma lookup table: maps uint8_t (0-255) to uint16_t
    gamma_lut = (uint16_t*)aligned_alloc(32, 256 * sizeof(uint16_t));
    if (!gamma_lut) exit(1);

    // Initialize gamma LUT with identity mapping scaled by 100 for non-trivial operation
    for (int idx = 0; idx < 256; idx++) {
        gamma_lut[idx] = (uint16_t)(idx * 100);
    }

    // Initialize row data with non-zero values to make transformations visible
    for (uint32_t idx = 0; idx < pixels * 4; idx++) {
        row[idx] = (unsigned char)(idx % 256);
    }

    // Initialize px to NULL to avoid dangling pointer before first loop iteration
    px = NULL;
}