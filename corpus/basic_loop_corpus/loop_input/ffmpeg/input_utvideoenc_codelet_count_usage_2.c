#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

uint8_t *src;
int width;
int height;
uint64_t *counts;
int i;
int j;

void init_vars() {
    // Target approximately 0.01 seconds runtime
    // Use ~16 million pixels (e.g., 4096x4096) as a reasonable data size
    width = 4096;
    height = 4096;
    
    // Allocate counts array for 256 possible uint8_t values
    counts = (uint64_t*)calloc(256, sizeof(uint64_t));
    if (!counts) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Allocate source image data
    src = (uint8_t*)malloc(width * height * sizeof(uint8_t));
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize src with random byte values to simulate realistic access pattern
    // Use deterministic seed for reproducibility
    srand(12345);
    for (int idx = 0; idx < width * height; idx++) {
        src[idx] = rand() % 256;
    }
}