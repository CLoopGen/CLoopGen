#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t x[32000];
__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];
extern real_t a1;
extern real_t b1;
extern real_t c1;
extern real_t d1;
extern real_t e1;
extern real_t f1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 10; nl++) {
    for (int i = 0; i < 256; i++) {
        int stride = 2;
        int idx = (i * stride) % 256;
        a1 = a[idx];
        b1 = b[idx];
        c1 = c[idx];
        d1 = d[idx];
        e1 = e[idx];
        f1 = aa[0][idx];
        a1 = a1 * b1 * c1 + a1 * b1 * d1 + a1 * b1 * e1 + a1 * b1 * f1 + a1 * c1 * d1 + a1 * c1 * e1 + a1 * c1 * f1 + a1 * d1 * e1 + a1 * d1 * f1 + a1 * e1 * f1;
        b1 = b1 * c1 * d1 + b1 * c1 * e1 + b1 * c1 * f1 + b1 * d1 * e1 + b1 * d1 * f1 + b1 * e1 * f1;
        c1 = c1 * d1 * e1 + c1 * d1 * f1 + c1 * e1 * f1;
        d1 = d1 * e1 * f1;
        x[idx] = a1 * b1 * c1 * d1;
    }
}
}
