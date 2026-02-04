#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 1000 * (100000 / 256); nl++) {
    for (int i = 1; i < 256; i++) {
        real_t temp = a[i];
        for (int j = 0; j < i; j++) {
            temp -= aa[j][i] * a[j];
        }
        a[i] = temp;
    }
}
}
