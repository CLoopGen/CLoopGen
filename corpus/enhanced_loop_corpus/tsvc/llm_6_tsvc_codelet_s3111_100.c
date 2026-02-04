#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    real_t local_sum = 0.0;
    for (int nl = 0; nl < 100000 / 2; nl++) {
        local_sum = 0.0;
        for (int i = 0; i < 32000; i++) {
            real_t val = a[i];
            if (val > (real_t)0.) {
                local_sum += val;
            }
        }
        sum = local_sum;
    }
}
