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
    for (int i = 0; i < 32000 / 2; i++) {
        real_t product1 = c[i] * b[i];
        real_t product2 = d[i] * b[i];
        real_t product3 = c[i] * c[i];
        real_t product4 = d[i] * c[i];
        a[2 * i] = product1 + product2 + product3 + product2 + product4;
        a[2 * i + 1] = product1 + product3; // Introduces WAW and WAR dependencies on 'a' across iterations if vectorized
    }
}
}
