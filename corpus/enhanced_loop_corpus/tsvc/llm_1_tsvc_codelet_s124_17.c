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
for (int nl = 0; nl < 1000; nl++) {  // Reduced outer loop count
    for (int nk = 0; nk < 100; nk++) {  // Split the original outer loop into two levels
        j = -1;
        int base = (nl * 100 + nk) % 32000;  // Use 2D-like indexing to traverse array
        for (int i = 0; i < 320 && (base + i) < 32000; i++) {
            int idx = base + i;
            if (b[idx] > (real_t)0.) {
                j++;
                a[j] = b[idx] + d[idx] * e[idx];
            } else {
                j++;
                a[j] = c[idx] + d[idx] * e[idx];
            }
        }
    }
}
}
