#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 4 * 100000; nl++) {
        s = 0.0f;
        for (int i = 0; i < 32000; i += 8) {
            for (int j = 0; j < 8 && (i + j) < 32000; j++) {
                int idx = i + j;
                real_t temp = b[idx] + c[idx];
                b[idx] = a[idx] + d[idx];
                a[idx] = temp * e[idx];
            }
        }
    }
}
