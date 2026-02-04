#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    for (int i = 0; i < 16000; i++) {
        real_t de1 = d[i] * e[i];
        real_t de2 = d[i + 16000] * e[i + 16000];
        if (a[i] > (real_t)0.) {
            c[i] = -c[i] + de1;
        } else {
            b[i] = -b[i] + de1;
        }
        a[i] = b[i] + c[i] * d[i];

        // Second half of the array processed independently
        if (a[i + 16000] > (real_t)0.) {
            c[i + 16000] = -c[i + 16000] + de2;
        } else {
            b[i + 16000] = -b[i + 16000] + de2;
        }
        a[i + 16000] = b[i + 16000] + c[i + 16000] * d[i + 16000];

        // Additional arithmetic to increase computational intensity
        b[i] = b[i] * 0.99f + a[i] * 0.01f;
        c[i + 16000] = c[i + 16000] * 0.99f + a[i + 16000] * 0.01f;
    }
}
}
