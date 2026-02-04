#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 4 * 100000; nl++) {
        real_t temp = 0.0f;
        for (int i = 0; i < 32000; i++) {
            temp += b[i] + c[i] * (real_t)(i + 1);
            a[i] = temp; // Introduces RAW dependency: each a[i] depends on cumulative temp (loop-carried)
        }
    }
}
