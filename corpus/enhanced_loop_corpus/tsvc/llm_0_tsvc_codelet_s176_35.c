#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * (100000 / 32000); nl++) {
    for (int j = 0; j < (32000 / 2); j++) {
        int i = 0;
        #pragma unroll(8)
        for (; i < m - 7; i += 8) {
            a[i]     += b[i + m - j - 1] * c[j];
            a[i + 1] += b[i + m - j]     * c[j];
            a[i + 2] += b[i + m - j + 1] * c[j];
            a[i + 3] += b[i + m - j + 2] * c[j];
            a[i + 4] += b[i + m - j + 3] * c[j];
            a[i + 5] += b[i + m - j + 4] * c[j];
            a[i + 6] += b[i + m - j + 5] * c[j];
            a[i + 7] += b[i + m - j + 6] * c[j];
        }
        for (; i < m; i++) {
            a[i] += b[i + m - j - 1] * c[j];
        }
    }
}
}
