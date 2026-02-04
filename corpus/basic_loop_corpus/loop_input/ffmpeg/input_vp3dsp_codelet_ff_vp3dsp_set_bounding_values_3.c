#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int filter_limit;
int *bounding_values;
int x;
int value;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    bounding_values = (int*)aligned_alloc(32, total_size * sizeof(int));
    
    for (size_t i = 0; i < total_size; i++) {
        bounding_values[i] = 0;
    }

    filter_limit = 512;
    x = 0;
    value = 0;
}

void loop();