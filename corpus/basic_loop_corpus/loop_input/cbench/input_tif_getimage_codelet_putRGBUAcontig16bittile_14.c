#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint32;
typedef unsigned short uint16;

uint32 *cp;
uint32 x;
uint32 w;
int samplesperpixel;
uint16 *wp;
uint32 r;
uint32 g;
uint32 b;
uint32 a;

static uint32 *cp_buffer;
static uint16 *wp_buffer;

void init_vars() {
    // Set data size to target ~0.01 seconds runtime
    // Empirical testing suggests ~64M iterations is about right for modern CPUs
    w = 64 * 1024 * 1024 / sizeof(uint32);  // ~64M pixels
    
    samplesperpixel = 4;  // wp has at least 4 elements accessed: 0,1,2,3
    
    // Allocate buffers with sufficient size
    cp_buffer = (uint32*)aligned_alloc(32, w * sizeof(uint32));
    wp_buffer = (uint16*)aligned_alloc(32, (w * samplesperpixel) * sizeof(uint16));
    
    // Initialize pointers
    cp = cp_buffer;
    wp = wp_buffer;
    
    // Initialize wp data to avoid division by zero or overflow
    for (uint32 i = 0; i < w * samplesperpixel; i++) {
        wp_buffer[i] = (i % 32) * 1000 + 1;  // Spread values safely in range
    }
    
    // Ensure no undefined behavior in loop
    r = g = b = a = 0;
}

// Ensure proper cleanup if needed in future
__attribute__((destructor))
void cleanup() {
    free(cp_buffer);
    free(wp_buffer);
}