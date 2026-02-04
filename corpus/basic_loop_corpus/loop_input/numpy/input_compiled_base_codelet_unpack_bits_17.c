#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int i;
npy_intp in_n;
npy_intp in_stride;
npy_intp out_stride;
npy_intp _usr_index;
unsigned char *inptr;
char *outptr;

#define index _usr_index

static unsigned char *in_buffer;
static char *out_buffer;

void init_vars() {
    // Set input size to approximately 32 million bytes to target ~0.01 sec runtime
    // Each input byte generates 8 output values, total operations ~256M
    in_n = 32 * 1024 * 1024;

    // Strides: process one byte at a time for input, one char at a time for output
    in_stride = 1;
    out_stride = 1;

    // Allocate input buffer
    in_buffer = (unsigned char *)aligned_alloc(64, in_n * sizeof(unsigned char));
    if (!in_buffer) exit(1);

    // Each input byte produces 8 output chars, so total output size is 8 * in_n
    out_buffer = (char *)aligned_alloc(64, 8 * in_n * sizeof(char));
    if (!out_buffer) exit(1);

    // Initialize input data with non-trivial bit patterns
    for (npy_intp idx = 0; idx < in_n; idx++) {
        in_buffer[idx] = (unsigned char)(idx ^ 0xAA);
    }

    // Initialize pointers
    inptr = in_buffer;
    outptr = out_buffer;

    // Reset index
    index = 0;
}