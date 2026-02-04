#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned short *x;
unsigned short newbyt;
unsigned short oldbyt;
int i;

static unsigned short *x_buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (2^20 bytes)
    x_buffer = (unsigned short*)aligned_alloc(16, data_size);
    
    if (!x_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < data_size / sizeof(unsigned short); ++j) {
        x_buffer[j] = (unsigned short)(j & 0xFFFF);
    }

    x = x_buffer;
    newbyt = 0;
    oldbyt = 0x1234;
    i = 0;
}