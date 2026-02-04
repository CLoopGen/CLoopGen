#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    j = -1;
    for (int i = 0; i < 32000 / 2; i += 2) {  // Stride-2 access on i
        k = j + 1;
        a[i] = b[k] - d[i];                  // Consecutive in steps of 2
        j = k + 1;
        b[k] = a[i] + c[k];
        if (i + 1 < 32000 / 2) {
            k = j + 1;
            a[i+1] = b[k] - d[i+1];
            j = k + 1;
            b[k] = a[i+1] + c[k];
        }
    }
}
}
