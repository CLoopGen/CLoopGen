#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    real_t *restrict A = a;
    real_t *restrict B = b;
    real_t *restrict C = c;
    for (int i = 0; i < 32000; i++) {
        *A = *B + *C;
        *(A + 1) = *(B + 1) + *(C + 1);
        A += 2;
        B += 2;
        C += 2;
        i++;
    }
}
}
