#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * 100000; nl++) {
    real_t temp_sum = 0.0f;
    for (int i = 0; i < 32000 / 2; i++) {
        temp_sum += a[i] + b[i];
        a[i + k] = temp_sum;
    }
}
}
