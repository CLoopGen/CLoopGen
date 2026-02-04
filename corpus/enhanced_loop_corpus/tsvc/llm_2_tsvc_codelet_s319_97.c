#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 2 * 100000; nl++) {
        sum = 0.;
        for (int i = 0; i < 32000; i += 4) {
            a[i] = c[i] + d[i];
            sum += a[i];
            b[i] = c[i] + e[i];
            sum += b[i];

            if (i+1 < 32000) {
                a[i+1] = c[i+1] + d[i+1];
                sum += a[i+1];
                b[i+1] = c[i+1] + e[i+1];
                sum += b[i+1];
            }
            if (i+2 < 32000) {
                a[i+2] = c[i+2] + d[i+2];
                sum += a[i+2];
                b[i+2] = c[i+2] + e[i+2];
                sum += b[i+2];
            }
            if (i+3 < 32000) {
                a[i+3] = c[i+3] + d[i+3];
                sum += a[i+3];
                b[i+3] = c[i+3] + e[i+3];
                sum += b[i+3];
            }
        }
    }
}
