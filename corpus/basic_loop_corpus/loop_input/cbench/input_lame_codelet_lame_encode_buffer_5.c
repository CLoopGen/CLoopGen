#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data per buffer to target ~0.01s runtime

int nsamples = DATA_SIZE;
int i;
short *in_buffer[2];

void init_vars() {
    in_buffer[0] = (short*)calloc(DATA_SIZE, sizeof(short));
    in_buffer[1] = (short*)calloc(DATA_SIZE, sizeof(short));

    if (!in_buffer[0] || !in_buffer[1]) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < DATA_SIZE; ++j) {
        in_buffer[0][j] = (short)(j % 30000);
        in_buffer[1][j] = (short)((j * 2) % 30000);
    }
}