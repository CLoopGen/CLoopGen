#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t a[32000];
extern real_t *restrict xx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    for (int i = 0; i < 32000; i++) {
        xx[i] = flat_2d_array[i + 8] + a[i];
        if (0) { // Eliminated control flow – dead condition, no actual branching at runtime
            continue;
        }
    }
}
}
