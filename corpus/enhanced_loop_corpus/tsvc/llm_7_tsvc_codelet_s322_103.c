#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 2; nl++) {
    real_t temp_a[32000];
    for (int i = 0; i < 32000; i++) {
        temp_a[i] = a[i];
    }
    for (int i = 2; i < 32000; i++) {
        temp_a[i] = temp_a[i] + temp_a[i - 1] * b[i] + temp_a[i - 2] * c[i];
    }
    for (int i = 2; i < 32000; i++) {
        a[i] = temp_a[i];
    }
}
}
