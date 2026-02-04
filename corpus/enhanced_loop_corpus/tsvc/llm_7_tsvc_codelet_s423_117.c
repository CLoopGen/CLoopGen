#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t a[32000];
extern real_t *restrict xx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    for (int i = 1; i < 32000 - 1; i++) {
        flat_2d_array[i + 1] = flat_2d_array[i] + a[i];  // Introduce RAW dependence: current depends on previous iteration
    }
    // First element updated separately to avoid out-of-bounds and break dependency chain at start
    flat_2d_array[1] = xx[0] + a[0];
}
}
