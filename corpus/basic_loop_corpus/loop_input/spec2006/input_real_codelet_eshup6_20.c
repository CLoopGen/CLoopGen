#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned short *x;
int i;
unsigned short *p;

static unsigned short *x_buf;
static unsigned short *p_buf;
static size_t data_size;

void init_vars() {
    data_size = 128 * (1 << 20); // 128 MB of data (64M elements for unsigned short)
    x_buf = (unsigned short*)aligned_alloc(64, data_size);
    p_buf = (unsigned short*)aligned_alloc(64, data_size);

    if (!x_buf || !p_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize x buffer with dummy data
    for (size_t idx = 0; idx < data_size / sizeof(unsigned short); idx++) {
        x_buf[idx] = (unsigned short)(idx & 0xFFFF);
    }

    // Set external pointers
    x = x_buf;
    p = p_buf;
}

__attribute__((destructor))
void cleanup() {
    free(x_buf);
    free(p_buf);
}