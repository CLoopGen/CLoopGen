#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    for (int i = 0; i < 32000; i += 2) {
        if (a[i] > b[i]) {
            s = a[i] - b[i] * d[i] + c[i] * 0.5f;
            c[i] += s * 2.0f;
            a[i] = s;
        }
        if (a[i+1] > b[i+1]) {
            s = a[i+1] - b[i+1] * d[i+1] + c[i+1] * 0.5f;
            c[i+1] += s * 2.0f;
            a[i+1] = s;
        }
    }
}
}
