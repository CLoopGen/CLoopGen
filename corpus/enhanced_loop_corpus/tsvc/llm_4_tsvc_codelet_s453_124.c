#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 2; nl++) {
    s = 0.;
    for (int i = 0; i < 32000; i++) {
        if (i % 2 == 0) {
            s += (real_t)2.;
        }
        a[i] = s * b[i];
    }
}
}
