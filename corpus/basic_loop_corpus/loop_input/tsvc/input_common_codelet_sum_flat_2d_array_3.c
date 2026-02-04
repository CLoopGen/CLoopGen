#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t flat_2d_array[65536];
real_t sum;

void init_vars() {
    for (int i = 0; i < 65536; i++) {
        flat_2d_array[i] = 1.0f;
    }
    sum = 0.0f;
}