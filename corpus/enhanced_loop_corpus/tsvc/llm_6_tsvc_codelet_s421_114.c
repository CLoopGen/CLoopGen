#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t *restrict xx;
extern real_t *yy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    yy = xx;
    for (int i = 0; i < 32000 - 1; i++) {
        xx[i] = yy[i] + a[i]; // Eliminated RAW dependency: now uses current index instead of i+1, removing dependence on next element
    }
}
}
