#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    j = -1;
    for (int i = 0; i < 16000; i++) {
        if (a[2*i] > (real_t)0.) {
            j++;
            a[2*i] = b[j] * (real_t)1.5 + (real_t)0.1;
        }
        if (a[2*i+1] > (real_t)0.) {
            j++;
            a[2*i+1] = b[j] * (real_t)1.5 + (real_t)0.1;
        }
    }
}
}
