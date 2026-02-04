#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    j = -1;
    for (int i = 0; i < 32000; i += 2) {
        if (b[i] > (real_t)0.) {
            j++;
            a[j] = b[i] * (real_t)2.0 + (real_t)1.0;
        }
        if (i + 1 < 32000 && b[i + 1] > (real_t)0.) {
            j++;
            a[j] = b[i + 1] * (real_t)2.0 + (real_t)1.0;
        }
    }
}
}
