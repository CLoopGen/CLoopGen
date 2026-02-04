#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define BUFFER_WIDTH (1280)
#define BUFFER_HEIGHT ((DATA_SIZE_MB * 1024 * 1024) / BUFFER_WIDTH)

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
uint8_t *cm;
int i;

static uint8_t internal_dst[BUFFER_HEIGHT][BUFFER_WIDTH];
static uint8_t internal_src[BUFFER_HEIGHT][BUFFER_WIDTH + 16]; // Extra padding for negative and forward indices
static uint8_t internal_cm[512]; // Extended range to cover possible index values safely

void init_vars() {
    // Initialize strides
    dstStride = BUFFER_WIDTH;
    srcStride = BUFFER_WIDTH + 16;
    
    // Set height to buffer height
    h = BUFFER_HEIGHT;
    
    // Assign pointers to internal buffers
    dst = &internal_dst[0][0];
    src = &internal_src[0][8]; // Offset by 8 so that src[-1] is valid
    
    cm = &internal_cm[256]; // Center cm at index 256 to allow signed-like indexing from -256 to 255
    
    // Initialize cm table: clamping function around valid pixel values [0,255]
    for (int idx = 0; idx < 512; idx++) {
        int val = idx - 256; // Map index range [-256, 255] -> actual values
        internal_cm[idx] = (val < 0) ? 0 : (val > 255) ? 255 : (uint8_t)val;
    }
    
    // Initialize src with random data in valid range [0,255], padded appropriately
    for (int y = 0; y < BUFFER_HEIGHT; y++) {
        for (int x = 0; x < BUFFER_WIDTH + 16; x++) {
            internal_src[y][x] = rand() & 0xFF;
        }
    }
    
    // Initialize dst to zero
    memset(internal_dst, 0, sizeof(internal_dst));
}