#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB for sufficient runtime (~0.01s on modern CPU)

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
uint8_t *cm;
int w;
int i;

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src[DATA_SIZE];
static uint8_t internal_cm[512]; // cm is indexed with offset up to ~several hundred, so 512 safe

void init_vars() {
    const int height = 16 + 1; // We access src[0..16] -> need 17 rows
    const int row_size = sizeof(uint8_t) * (height);
    
    // Set strides to 1 for simplicity and dense access
    dstStride = 1;
    srcStride = 1;
    
    // Initialize global pointers to point into our internal buffers
    dst = internal_dst;
    src = internal_src;
    
    // Ensure we don't go out of bounds: w must be such that we don't overflow buffer in loop
    // Each iteration increments dst and src by 1 -> maximum w is limited by available width
    w = (DATA_SIZE / height) - 16; // Leave margin for 16 steps forward in each column
    
    cm = internal_cm;
    
    // Initialize cm with identity-like mapping to avoid undefined behavior
    for (int idx = 0; idx < 512; idx++) {
        cm[idx] = (uint8_t)(idx & 0xFF);
    }
    
    // Initialize src and dst with non-zero predictable data
    for (int j = 0; j < DATA_SIZE; j++) {
        internal_src[j] = (uint8_t)(j & 0xFF);
        internal_dst[j] = (uint8_t)((j ^ 0x5A) & 0xFF);
    }
}