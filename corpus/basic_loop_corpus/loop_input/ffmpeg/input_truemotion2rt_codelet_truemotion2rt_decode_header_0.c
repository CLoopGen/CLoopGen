#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB for ~0.01 sec runtime on modern CPU

int header_size;
uint8_t header_buffer[128];
uint8_t *buf;
int i;

void init_vars() {
    header_size = 128; // Ensures loop runs from i=1 to i<header_size, accessing buf[i] and buf[i+1]
    
    // Allocate buffer with extra space to prevent out-of-bounds access: we access up to buf[header_size] (i+1 when i = header_size-1)
    buf = (uint8_t*)calloc(DATA_SIZE, sizeof(uint8_t));
    if (!buf) {
        exit(1);
    }

    // Ensure at least header_size + 1 elements are accessible in buf
    for (int j = 0; j < header_size + 1; j++) {
        buf[j] = (uint8_t)(j * 31); // Initialize with non-zero pattern
    }
}