#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    s = 0.;
    for (int nl = 0; nl < 100000; nl++) {
        for (int i = 0; i < 32000; i += 4) {
            s += (real_t)2.0;
            a[i]     = s * b[i];
            if (i + 1 < 32000) a[i + 1] = s * b[i + 1];
            if (i + 2 < 32000) a[i + 2] = s * b[i + 2];
            if (i + 3 < 32000) a[i + 3] = s * b[i + 3];
        }
    }
}
