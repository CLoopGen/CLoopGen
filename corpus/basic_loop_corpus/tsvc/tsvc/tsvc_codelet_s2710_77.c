#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int x;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int nl = 0; nl < 100000 / 2; nl++) {
    for (int i = 0; i < 32000; i++) {
        if (a[i] > b[i]) {
            a[i] += b[i] * d[i];
            if (32000 > 10) {
                c[i] += d[i] * d[i];
            } else {
                c[i] = d[i] * e[i] + (real_t)1.;
            }
        } else {
            b[i] = a[i] + e[i] * e[i];
            if (x > (real_t)0.) {
                c[i] = a[i] + d[i] * d[i];
            } else {
                c[i] += e[i] * e[i];
            }
        }
    }
}

}
