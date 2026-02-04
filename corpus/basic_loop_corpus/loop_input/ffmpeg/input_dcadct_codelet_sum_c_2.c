#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *input;
int *output;
int len;
int i;

void init_vars() {
    len = 32 * 1024 * 1024; // ~128MB of input data (32M int elements * 4 bytes)

    input = (int*)aligned_alloc(32, 2 * len * sizeof(int));
    output = (int*)aligned_alloc(32, len * sizeof(int));

    if (!input || !output) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < 2 * len; j++) {
        input[j] = rand();
    }

    for (int j = 0; j < len; j++) {
        output[j] = 0;
    }
}