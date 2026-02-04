#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *input;
int *output;
int len;
int i;

void init_vars() {
    len = 32 * 1024 * 1024;  // 32 million integers, ~128 MB of input data

    input = (int*)aligned_alloc(32, 2 * len * sizeof(int));
    output = (int*)aligned_alloc(32, len * sizeof(int));

    for (int j = 0; j < 2 * len; j++) {
        input[j] = rand() % 1000;
    }
    for (int j = 0; j < len; j++) {
        output[j] = 0;
    }
    i = 0;
}