#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 length;
png_bytep buffer;
png_uint_32 prefix_length;

void init_vars() {
    // Allocate approximately 64MB of data to target ~0.01s runtime on modern CPUs
    length = 64 * 1024 * 1024;
    buffer = (png_bytep)malloc(length);
    if (!buffer) {
        exit(1);
    }

    // Fill buffer with non-zero bytes initially
    memset(buffer, 1, length);

    // Place a zero near the end to ensure loop terminates within bounds
    // This ensures prefix_length stops at length - 1
    buffer[length - 1] = 0;

    // Initialize prefix_length to 0 to start scanning from beginning
    prefix_length = 0;
}