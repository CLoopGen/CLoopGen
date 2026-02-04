#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t *restrict xx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl += 2) {
    for (int nj = 0; nj < 2; nj++) {
        for (int i = 0; i < 32000 / 2; i++) {
            b[i] = xx[i] + a[i];
        }
    }
}
}
