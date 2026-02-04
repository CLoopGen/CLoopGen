#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t a[32000];
extern real_t *restrict xx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    for (int i = 31999; i > 0; i--) {
        flat_2d_array[i] = xx[i - 1] + a[i - 1];
    }
}
}
