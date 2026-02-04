#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    for (int nb = 0; nb < 16000; nb++) {
        int i = 2 * nb + 1;
        if (i < 32000) {
            a[i] = a[i - 1] + b[i];
        }
    }
}
}
