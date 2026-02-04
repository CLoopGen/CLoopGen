#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct roq_cell {
    unsigned char y[4];
    unsigned char u;
    unsigned char v;
} roq_cell;

roq_cell *results;
int cbsize;
int i;
int j;
int k;
int c_size;
int *buf;

void init_vars() {
    // Set parameters to control total workload
    c_size = 65536;  // Number of cells per block
    cbsize = 4;      // Number of blocks

    // Total integers consumed: cbsize * c_size * (4 + 1 + 1) = 4 * 65536 * 6 = 1,572,864 integers
    size_t total_ints = cbsize * c_size * 6;
    buf = (int*)malloc(total_ints * sizeof(int));
    if (!buf) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with predictable values
    for (size_t idx = 0; idx < total_ints; idx++) {
        buf[idx] = (idx % 256) + 1;
    }

    // Allocate results array
    results = (roq_cell*)malloc(cbsize * c_size * sizeof(roq_cell));
    if (!results) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}