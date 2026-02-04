#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int n1;
extern int n3;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    j = 1;
    k = 0;
    for (int i = n1 - 1; i < 32000; i += n3) {
        k += j;
        a[i] += b[32000 - k];
        a[i] += b[(32000 - k + 16000) % 32000]; // Additional memory access and arithmetic
        a[i] *= 1.05f; // Additional floating-point operation to increase computational intensity
    }
}
}
