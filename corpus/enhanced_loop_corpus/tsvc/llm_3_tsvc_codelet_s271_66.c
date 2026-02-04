#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    for (int i = 0; i < 32000; i++) {
        int idx = (i * 7) % 32000; // Strided access with prime stride effect via modulo
        if (b[idx] > (real_t)0.) {
            a[idx] += b[idx] * c[idx];
        }
    }
}
}
