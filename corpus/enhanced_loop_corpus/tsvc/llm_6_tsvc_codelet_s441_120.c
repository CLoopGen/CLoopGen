#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    real_t temp_a = a[0]; // Introduce loop-carried dependence: WAW and RAW dependency across iterations
    for (int i = 0; i < 32000; i++) {
        real_t update;
        if (d[i] < (real_t)0.) {
            update = b[i] * c[i];
        } else if (d[i] == (real_t)0.) {
            update = b[i] * b[i];
        } else {
            update = c[i] * c[i];
        }
        a[i] += update;
        // Create loop-carried dependency: each 'a[i]' affects next iteration's base value
        temp_a = a[i]; // WAW: write after write on temp_a; RAW: read after write in next loop use
    }
    a[0] = temp_a; // Reinforce loop-carried WAW on a[0] between outer loop iterations
}
}
