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
    const int stride = 8;
    for (int nl = 0; nl < 2 * 100000; nl++) {
        sum = 0.;
        for (int phase = 0; phase < stride; phase++) {
            for (int i = phase; i < 32000; i += stride) {
                a[i] = c[i] + d[i];
                sum += a[i];
                b[i] = c[i] + e[i];
                sum += b[i];
            }
        }
    }
}
