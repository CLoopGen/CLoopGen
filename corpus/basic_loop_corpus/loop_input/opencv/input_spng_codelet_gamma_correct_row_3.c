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
    // Allocate a row buffer of approximately 64MB to target ~0.01s runtime
    // Each pixel is 3 bytes, and we process each pixel in the loop
    size_t total_bytes = 67108864; // ~64MB
    pixels = total_bytes / 3; // Number of 3-byte pixels
    row = (unsigned char*)aligned_alloc(32, total_bytes);
    
    // Initialize gamma lookup table (256 entries for 8-bit input)
    gamma_lut = (uint16_t*)aligned_alloc(32, 256 * sizeof(uint16_t));
    for (int i = 0; i < 256; i++) {
        gamma_lut[i] = (uint16_t)((i * 1.5) > 255 ? 255 : (i * 1.5));
    }
    
    // Initialize row data with valid byte values
    for (size_t i = 0; i < total_bytes; i++) {
        row[i] = rand() % 256;
    }
    
    // Ensure px is initialized inside the loop, so no need to set here
    i = 0;
    px = NULL;
}