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
        if (a[i] > (real_t)0.) {
            j++;
            a[i] = b[j];
        }
        if (a[i+1] > (real_t)0. && (i+1) < 32000) {
            j++;
            a[i+1] = b[j];
        }
    }
}
}
