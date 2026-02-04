#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t bytes_per_line;
unsigned char *p;
ssize_t i;
unsigned char *q;
ssize_t count;
ssize_t repeat_count;
ssize_t runlength;
unsigned char _usr_index;

#define index _usr_index

static unsigned char *input_buffer;
static unsigned char *output_buffer;

void init_vars() {
    // Set up problem size to take ~0.01 seconds
    // Empirically, 64MB input tends to be around that on modern CPUs
    bytes_per_line = 64 * 1024 * 1024; // 64 MB

    // Allocate input and output buffers
    input_buffer = aligned_alloc(64, bytes_per_line);
    output_buffer = aligned_alloc(64, bytes_per_line + 1024); // extra room for RLE expansion

    // Initialize buffers
    for (size_t j = 0; j < bytes_per_line; j++) {
        input_buffer[j] = (unsigned char)(j % 255 + 1);
    }

    // Setup pointers
    p = input_buffer + bytes_per_line - 1; // points to last byte
    q = output_buffer;

    // Initialize scalar variables
    i = 0;
    count = 0;
    repeat_count = 0;
    runlength = 1;
    index = input_buffer[bytes_per_line - 1]; // initial index value
}