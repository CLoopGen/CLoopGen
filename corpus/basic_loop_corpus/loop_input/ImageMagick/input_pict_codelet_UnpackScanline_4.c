#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned long long MagickSizeType;

MagickSizeType *bytes_per_line;
unsigned char *p;
ssize_t i;
unsigned char *q;

static unsigned char *p_buffer;
static unsigned char *q_buffer;

void init_vars() {
    // Allocate input buffer: 64MB for ~0.01s runtime on modern CPU
    size_t input_size = 64 * 1024 * 1024;
    p_buffer = (unsigned char *)calloc(input_size, sizeof(unsigned char));
    if (!p_buffer) exit(1);
    
    // Initialize input data with non-zero pattern
    for (size_t idx = 0; idx < input_size; idx++) {
        p_buffer[idx] = (unsigned char)(idx ^ 0xAA);
    }
    
    // Each byte produces 8 output bytes, so q needs 8x space
    size_t output_size = input_size * 8;
    q_buffer = (unsigned char *)calloc(output_size, sizeof(unsigned char));
    if (!q_buffer) exit(1);
    
    // Initialize external pointers and variables
    bytes_per_line = (MagickSizeType *)malloc(sizeof(MagickSizeType));
    if (!bytes_per_line) exit(1);
    *bytes_per_line = input_size;
    
    p = p_buffer;
    q = q_buffer;
    i = 0;
}

// Cleanup function to avoid memory leaks (not called here but implied usage)
// Caller should free allocated resources after loop execution