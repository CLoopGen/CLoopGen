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
    sum = 0.;
    for (int nl = 0; nl < 2 * 100000; nl++) {
        for (int i = 0; i < 32000; i += 8) {
            for (int j = 0; j < 8; j++) {
                int idx = i + j;
                a[idx] = c[idx] + d[idx];
                sum += a[idx];
                b[idx] = c[idx] + e[idx];
                sum += b[idx];
            }
        }
    }
}
