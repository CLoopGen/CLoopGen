#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 2 * 100000; nl++) {
        for (int i = 0; i < 32000 / 4; i++) {
            for (int j = 0; j < 2; j++) {
                int idx = 2 * (i * 2 + j);
                a[idx] = c[i*2+j] * b[i*2+j] + d[i*2+j] * b[i*2+j] + 
                         c[i*2+j] * c[i*2+j] + d[i*2+j] * b[i*2+j] + 
                         d[i*2+j] * c[i*2+j];
            }
        }
    }
}
