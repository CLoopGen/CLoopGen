#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int int32;
typedef unsigned int uint32;

int32 n_el;
uint32 sum;
int32 i;
uint32 *i32;

void init_vars() {
    const size_t data_size = 64 * (1 << 20); // 64 MB of data
    const size_t num_elements = data_size / sizeof(uint32);
    n_el = (int32)num_elements;
    sum = 0;
    i = 0;

    i32 = (uint32*)malloc(num_elements * sizeof(uint32));
    if (!i32) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        i32[idx] = (uint32)(idx * 7919); // Arbitrary deterministic pattern
    }
}