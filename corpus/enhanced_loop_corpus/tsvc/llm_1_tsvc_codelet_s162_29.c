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
        for (int i = 0; i < 32000 - 1; i += 8) {
            for (int j = 0; j < 8 && (i + j) < 32000 - 1; j++) {
                a[i + j] = a[i + j + k] + b[i + j] * c[i + j];
            }
        }
    }
}
}
