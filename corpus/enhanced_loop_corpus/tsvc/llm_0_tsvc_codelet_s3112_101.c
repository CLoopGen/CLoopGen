#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    sum = (real_t)0.;
    for (int nl = 0; nl < 100000; nl++) {
        for (int i = 0; i < 32000; i++) {
            sum += a[i];
            b[i] = sum;
        }
    }
}
