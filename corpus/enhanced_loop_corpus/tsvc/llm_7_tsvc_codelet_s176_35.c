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
    for (int i = 0; i < m; i++) {
        real_t temp_a = a[i];
        for (int j = 0; j < (32000 / 2); j++) {
            temp_a += b[i + m - j - 1] * c[j];
        }
        a[i] = temp_a;
    }
}
}
