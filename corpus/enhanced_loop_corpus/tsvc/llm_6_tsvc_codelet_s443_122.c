#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    real_t temp_sum = 0.0;
    for (int i = 0; i < 32000; i++) {
        if (d[i] <= (real_t)0.) {
            a[i] += b[i] * c[i];
            temp_sum += a[i]; // Introduce RAW: current a[i] used in temp_sum
        } else {
            a[i] += b[i] * b[i];
            temp_sum += a[i]; // Loop-carried dependence via temp_sum (accumulation)
        }
    }
    // Use temp_sum to create artificial loop-carried dependency across iterations
    if (temp_sum > 0) {
        a[0] += temp_sum * 0.001; // WAW on a[0] across outer loop iterations
    }
}
}
