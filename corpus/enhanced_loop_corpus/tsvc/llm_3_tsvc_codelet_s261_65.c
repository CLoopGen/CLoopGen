#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern real_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int k = 0; k < 16000; ++k) {
        int i = (k & 15) * 2000 + (k >> 4); // Indirect-like access via index mapping
        if (i >= 1 && i < 32000) {
            t = a[i] + b[i];
            a[i] = t + c[i - 1];
            t = c[i] * d[i];
            c[i] = t;
        }
    }
}
}
