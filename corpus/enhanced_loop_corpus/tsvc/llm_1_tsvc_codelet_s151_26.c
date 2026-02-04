#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 5 * 100000; nl++) {
    for (int nj = 0; nj < 10; nj++) {
        for (int i = 0; i < 3200; i++) {
            int idx = i + nj * 3200;
            if (idx < 32000 - 1) {
                a[idx] = a[idx + m] + b[idx];
            }
        }
    }
}
}
