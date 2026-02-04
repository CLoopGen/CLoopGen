#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    j = -1;
    for (int i = 0; i < 32000; i++) {
        j += (b[i] > (real_t)0.) ? 1 : 0;
        if (b[i] > (real_t)0.) {
            a[j] = b[i];
        }
    }
}
}
