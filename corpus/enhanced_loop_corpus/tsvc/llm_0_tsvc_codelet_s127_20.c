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
    for (int nl = 0; nl < 2 * 100000; nl++) {
        j = -1;
        for (int i = 0; i < 32000 / 4; i++) {
            for (int k = 0; k < 2; k++) {
                int idx = i * 2 + k;
                j++;
                a[j] = b[idx] + c[idx] * d[idx];
                j++;
                a[j] = b[idx] + d[idx] * e[idx];
            }
        }
    }
}
