#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 2; nl++) {
    for (int i = 0; i < 32000; i += 4) {
        // Unroll and introduce WAW dependency by reordering writes to a[i]
        real_t temp_b0, temp_b1, temp_b2, temp_b3;
        real_t temp_c0, temp_c1, temp_c2, temp_c3;

        // Process 4 elements with temporary variables to break immediate dependencies
        if (a[i] > (real_t)0.) {
            temp_c0 = -c[i] + e[i] * e[i];
        } else {
            b[i] = -b[i] + d[i] * d[i];
            if (b[i] <= a[i]) {
                temp_c0 = c[i];
            } else {
                temp_c0 = c[i] + d[i] * e[i];
            }
        }
        a[i] = b[i] + temp_c0 * d[i];  // WAW: write-after-write on a[i] delayed

        if (i+1 < 32000) {
            if (a[i+1] > (real_t)0.) {
                temp_c1 = -c[i+1] + e[i+1] * e[i+1];
            } else {
                b[i+1] = -b[i+1] + d[i+1] * d[i+1];
                if (b[i+1] <= a[i+1]) {
                    temp_c1 = c[i+1];
                } else {
                    temp_c1 = c[i+1] + d[i+1] * e[i+1];
                }
            }
            a[i+1] = b[i+1] + temp_c1 * d[i+1];
        }

        if (i+2 < 32000) {
            if (a[i+2] > (real_t)0.) {
                temp_c2 = -c[i+2] + e[i+2] * e[i+2];
            } else {
                b[i+2] = -b[i+2] + d[i+2] * d[i+2];
                if (b[i+2] <= a[i+2]) {
                    temp_c2 = c[i+2];
                } else {
                    temp_c2 = c[i+2] + d[i+2] * e[i+2];
                }
            }
            a[i+2] = b[i+2] + temp_c2 * d[i+2];
        }

        if (i+3 < 32000) {
            if (a[i+3] > (real_t)0.) {
                temp_c3 = -c[i+3] + e[i+3] * e[i+3];
            } else {
                b[i+3] = -b[i+3] + d[i+3] * d[i+3];
                if (b[i+3] <= a[i+3]) {
                    temp_c3 = c[i+3];
                } else {
                    temp_c3 = c[i+3] + d[i+3] * e[i+3];
                }
            }
            a[i+3] = b[i+3] + temp_c3 * d[i+3];
        }
    }
}
}
