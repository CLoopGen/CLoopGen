#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t *restrict xx;
extern real_t *yy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    yy = xx;
    for (int i = 0; i < 32000 - 2; i += 2) {
        xx[i] = yy[i + 1] + a[i];
        xx[i + 1] = yy[i + 2] + a[i + 1];
    }
}
}
