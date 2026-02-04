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

static unsigned char *in_data;
static char *out_data;

void init_vars() {
    // Set data size to achieve ~0.01 seconds runtime
    // The inner loop runs 8 times per input byte, so total operations = 8 * in_n
    // Target around 64M to 128M operations for ~0.01s on modern CPU
    // Let's choose in_n = 16M => 128M operations
    in_n = 16 * 1024 * 1024;  // 16 million elements

    in_stride = 1;   // typical contiguous stride
    out_stride = 1;  // output advances by 1 per bit

    // Allocate input and output buffers
    in_data = (unsigned char *)calloc(in_n, sizeof(unsigned char));
    // Output has 8 entries per input byte
    out_data = (char *)calloc(in_n * 8, sizeof(char));

    if (!in_data || !out_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize inptr and outptr
    inptr = in_data;
    outptr = out_data;

    // Initialize input data with non-trivial test pattern
    for (npy_intp idx = 0; idx < in_n; idx++) {
        in_data[idx] = (unsigned char)(idx ^ (idx >> 8));
    }

    // Reset index for loop
    index = 0;
}