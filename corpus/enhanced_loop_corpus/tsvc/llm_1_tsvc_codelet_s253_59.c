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
for (int nl = 0; nl < 100000; nl++) {
    int i = 0;
    for (; i < 32000; ) {
        if (a[i] > b[i]) {
            s = a[i] - b[i] * d[i];
            c[i] += s;
            a[i] = s;
        }
        i++;
    }
}
}
