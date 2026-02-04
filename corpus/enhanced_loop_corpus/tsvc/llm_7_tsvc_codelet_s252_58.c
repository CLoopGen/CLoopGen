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
    for (int i = 0; i < 32000; i += 2) {
        real_t s1 = b[i] * c[i];
        real_t s2 = (i+1 < 32000) ? b[i+1] * c[i+1] : s1;
        a[i] = s1 + t;
        if (i+1 < 32000) {
            a[i+1] = s2 + s1;
        }
        t = (i+1 < 32000) ? s2 : s1;
    }
}
}
