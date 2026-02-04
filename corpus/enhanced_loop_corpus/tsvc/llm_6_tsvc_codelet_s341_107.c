#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    j = -1;
    int temp_j = 0;
    real_t temp_a[32000];
    for (int i = 0; i < 32000; i++) {
        if (b[i] > (real_t)0.) {
            temp_a[temp_j] = b[i];
            temp_j++;
        }
    }
    for (int k = 0; k < temp_j; k++) {
        a[k] = temp_a[k];
    }
    j = temp_j - 1;
}
}
