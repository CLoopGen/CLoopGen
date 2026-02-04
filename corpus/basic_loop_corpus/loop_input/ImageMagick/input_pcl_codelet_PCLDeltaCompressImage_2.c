#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>

size_t length;
unsigned char *previous_pixels;
unsigned char *pixels;
int delta;
int j;
int replacement;
ssize_t i;
ssize_t x;
unsigned char *q;

#define DATA_SIZE (64 * 1024 * 1024)  // 64 MB to target ~0.01 sec runtime

static unsigned char *buffer1;
static unsigned char *buffer2;
static unsigned char *output_buffer;

void init_vars() {
    // Allocate input buffers
    buffer1 = aligned_alloc(64, DATA_SIZE);
    buffer2 = aligned_alloc(64, DATA_SIZE);
    output_buffer = aligned_alloc(64, DATA_SIZE * 2);  // Conservative estimate for output size

    if (!buffer1 || !buffer2 || !output_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize with pseudo-random but deterministic data
    srand(12345);
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        buffer1[idx] = rand() & 0xFF;
        buffer2[idx] = rand() & 0xFF;
    }

    // Set external variables
    length = DATA_SIZE;
    previous_pixels = buffer1;
    pixels = buffer2;
    q = output_buffer;
    i = 0;
    x = 0;
    j = 0;
    replacement = 0;
    delta = 0;
}