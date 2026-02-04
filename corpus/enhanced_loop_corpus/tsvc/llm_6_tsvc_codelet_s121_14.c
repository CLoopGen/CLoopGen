#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 3 * 100000; nl++) {
    real_t temp[32000];
    for (int i = 0; i < 32000 - 1; i++) {
        j = i + 1;
        temp[i] = a[j] + b[i];
    }
    for (int i = 0; i < 32000 - 1; i++) {
        a[i] = temp[i];
    }
}
}
