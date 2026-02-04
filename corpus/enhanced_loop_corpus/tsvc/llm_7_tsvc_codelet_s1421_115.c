#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t *restrict xx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    real_t temp_sum = 0.0f;
    for (int i = 0; i < 32000 / 2; i++) {
        temp_sum += xx[i] + a[i]; // Eliminated output dependency; accumulation into local scalar
    }
    b[0] = temp_sum; // Store final result to break potential loop-carried dependence through memory
}
}
