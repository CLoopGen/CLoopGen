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

static unsigned char in_buffer[1 << 20]; // 1MB input buffer
static char out_buffer[1 << 20];

void init_vars() {
    in_tail = 8; // Ensure we only shift 128 by up to 7 bits (i from 0 to 7)
    out_stride = 1;
    inptr = in_buffer;
    outptr = out_buffer;
    *inptr = 0b10101010; // Example byte with alternating bits
}