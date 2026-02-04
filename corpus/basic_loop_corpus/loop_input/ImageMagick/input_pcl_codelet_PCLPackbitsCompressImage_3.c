#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t length;
unsigned char *pixels;
int count;
ssize_t x;
unsigned char *q;
ssize_t j;
unsigned char packbits[128];

unsigned char *output_buffer;

void init_vars() {
    // Set input size to ~64MB to achieve around 0.01s runtime on modern CPUs
    length = 64 * 1024 * 1024;
    
    // Allocate input and output buffers
    pixels = (unsigned char *)malloc(length * sizeof(unsigned char));
    output_buffer = (unsigned char *)malloc(2 * length * sizeof(unsigned char)); // worst-case larger output
    q = output_buffer;

    // Initialize pixels with a pattern that triggers both RLE and literal cases
    for (size_t i = 0; i < length; i += 7) {
        // Create runs of 3 or more same values (for RLE encoding)
        unsigned char val = (unsigned char)(i / 7 + 1);
        size_t run_len = (i + 5 <= length) ? 5 : 1;
        for (size_t j = 0; j < run_len && i + j < length; j++) {
            pixels[i + j] = val;
        }
        
        // Fill remaining with varying values
        for (size_t j = run_len; j < 7 && i + j < length; j++) {
            pixels[i + j] = (unsigned char)(val + j);
        }
    }

    // Initialize other loop control variables
    x = (ssize_t)length;
    count = 0;
    j = 0;

    // Initialize packbits (first element will be overwritten in loop)
    memset(packbits, 0, sizeof(packbits));
}