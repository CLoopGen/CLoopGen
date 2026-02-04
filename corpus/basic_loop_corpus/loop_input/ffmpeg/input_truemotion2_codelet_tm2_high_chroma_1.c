#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *data;
int stride;
int *last;
unsigned int *CD;
int *deltas;
int i;
int j;

static int data_buf[256 * 1024];     // ~1MB buffer for data (256K ints)
static int last_buf[2];
static unsigned int CD_buf[2];
static int deltas_buf[4];            // 2x2 = 4 elements (i + j*2 indexing)

void init_vars() {
    // Initialize scalar variables
    stride = 2;  // ensures data += stride moves by 2 ints

    // Initialize pointers to point to allocated buffers
    data = data_buf;
    last = last_buf;
    CD = CD_buf;
    deltas = deltas_buf;

    // Initialize array contents to avoid undefined behavior
    for (int idx = 0; idx < 2; idx++) {
        last[idx] = 0;
        CD[idx] = 0;
    }
    for (int idx = 0; idx < 4; idx++) {
        deltas[idx] = 1;  // arbitrary initialization
    }

    // Initialize data buffer to zero
    for (int idx = 0; idx < 256 * 1024; idx++) {
        data_buf[idx] = 0;
    }

    // Ensure loop bounds are safe: outer loop j=0..1, inner i=0..1
    // All memory accesses: deltas[i + j*2] -> indices 0,1,2,3 valid
    // last[i], data[i] for i in {0,1} -> safe
    // data is updated with stride, but only used in two iterations
}