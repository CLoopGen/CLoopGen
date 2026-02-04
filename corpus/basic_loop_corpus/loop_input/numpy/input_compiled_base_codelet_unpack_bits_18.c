#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int i;
npy_intp in_tail;
npy_intp out_stride;
unsigned char *inptr;
char *outptr;

#define DATA_SIZE (1 << 20)  // 1MB of input data

static unsigned char in_buffer[DATA_SIZE];
static char out_buffer[DATA_SIZE * 8];  // Large enough for stride access

void init_vars() {
    in_tail = 8;  // Number of bits to process (must be <= 8 for one byte)
    out_stride = 1;  // Default stride: consecutive elements
    inptr = in_buffer;
    outptr = out_buffer;
    
    // Initialize input buffer with non-zero test pattern
    for (int j = 0; j < DATA_SIZE; j++) {
        in_buffer[j] = (unsigned char)(j * 79 + 3);
    }
    
    // Ensure output buffer is zeroed initially
    for (int j = 0; j < DATA_SIZE * 8; j++) {
        out_buffer[j] = 0;
    }
}