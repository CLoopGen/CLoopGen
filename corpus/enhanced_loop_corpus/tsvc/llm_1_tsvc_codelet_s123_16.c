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
// Increase loop nesting depth by splitting outer loop into two levels
for (int nl1 = 0; nl1 < 500; nl1++) {
    for (int nl2 = 0; nl2 < 200; nl2++) { // 500 * 200 = 100,000 total iterations
        j = -1;
        for (int i = 0; i < (32000 / 2); i++) {
            j++;
            a[j] = b[i] + d[i] * e[i];
            if (c[i] > (real_t)0.) {
                j++;
                a[j] = c[i] + d[i] * e[i];
            }
        }
    }
}
}
