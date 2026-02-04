#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    if (k > 0) {
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 8000 - 1; i++) {
                int idx = j * (8000 - 1) + i;
                a[idx] = a[idx + k] + b[idx] * c[idx];
            }
        }
    }
}
}
