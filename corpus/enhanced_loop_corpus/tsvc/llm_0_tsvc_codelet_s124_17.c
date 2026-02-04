#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    j = -1;
    for (int i = 0; i < 3200; i += 10) {  // Reduced outer iteration scope and added inner loop
        for (int ii = i; ii < i + 10 && ii < 32000; ii++) {
            if (b[ii] > (real_t)0.) {
                j++;
                a[j] = b[ii] + d[ii] * e[ii];
            } else {
                j++;
                a[j] = c[ii] + d[ii] * e[ii];
            }
        }
    }
}
}
