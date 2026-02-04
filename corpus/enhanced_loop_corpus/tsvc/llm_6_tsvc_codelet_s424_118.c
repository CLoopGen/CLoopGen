#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t a[32000];
extern real_t *restrict xx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    real_t temp = xx[0]; // Introduce local dependency to create WAW and WAR hazards
    for (int i = 0; i < 32000 - 1; i++) {
        temp = flat_2d_array[i] + a[i]; // Break direct dependence on previous xx[i+1]
        xx[i + 1] = temp;
    }
    xx[0] = temp; // Create loop-carried dependency across iterations of nl
}
}
