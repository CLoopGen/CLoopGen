#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
extern real_t t;
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    t = (real_t)0.;
    for (int i = 0; i < 32000; i += 4) {
        s = b[i] * c[i];
        a[i] = s + t;
        t = s;

        if (i + 1 < 32000) {
            s = b[i+1] * c[i+1];
            a[i+1] = s + t;
            t = s;
        }
        if (i + 2 < 32000) {
            s = b[i+2] * c[i+2];
            a[i+2] = s + t;
            t = s;
        }
        if (i + 3 < 32000) {
            s = b[i+3] * c[i+3];
            a[i+3] = s + t;
            t = s;
        }
    }
}
}
