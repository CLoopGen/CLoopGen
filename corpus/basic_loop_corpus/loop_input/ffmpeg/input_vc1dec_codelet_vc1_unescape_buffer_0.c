#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t src_size;
static size_t dst_capacity;

void init_vars() {
    // Allocate approximately 64MB for input to target ~0.01s runtime on modern CPU
    src_size = 64 * 1024 * 1024;
    dst_capacity = src_size + 1024 * 1024; // Extra space for expansion

    src_buffer = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    dst_buffer = (uint8_t*)calloc(dst_capacity, sizeof(uint8_t));
    
    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    // Initialize source data with pattern that triggers some conditional matches
    for (size_t idx = 0; idx < src_size; idx++) {
        if (idx >= 2 && idx < src_size - 1) {
            // Create occasional match: src[0]==3, prev two zero, next <4
            if (idx % 1000 == 0) {
                src_buffer[idx] = 3;
                src_buffer[idx-1] = 0;
                src_buffer[idx-2] = 0;
                src_buffer[idx+1] = 2; // <4 to satisfy condition
                continue;
            }
        }
        // Random-like fill otherwise
        src_buffer[idx] = (uint8_t)((idx * 7919) % 256);
    }

    // Set extern variables
    src = src_buffer;
    size = (int)src_size;
    dst = dst_buffer;
    dsize = 0;
    i = 0;
}