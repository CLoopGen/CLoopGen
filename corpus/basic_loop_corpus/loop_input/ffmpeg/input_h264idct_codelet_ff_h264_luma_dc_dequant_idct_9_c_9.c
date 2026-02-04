#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int i;
int temp[16];
int32_t *input;

void init_vars() {
    const size_t input_size = 1024 * 1024; // ~4MB of data to ensure loop runtime ~0.01s
    input = (int32_t*)aligned_alloc(32, input_size * sizeof(int32_t));
    
    if (!input) {
        exit(1);
    }

    for (size_t idx = 0; idx < input_size; idx++) {
        input[idx] = (int32_t)(rand() % 1000);
    }
}