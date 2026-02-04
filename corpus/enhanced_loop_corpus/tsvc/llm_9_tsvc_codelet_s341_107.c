#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    j = -1;
    for (int i = 0; i < 16000; i++) {
        real_t val1 = b[i];
        real_t val2 = b[i + 16000];
        real_t sum = val1 + val2;
        real_t avg = sum * (real_t)0.5;
        if (avg > (real_t)0.) {
            j++;
            a[j] = avg;
        }
    }
}
}
