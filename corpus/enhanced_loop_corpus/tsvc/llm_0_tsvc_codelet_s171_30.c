#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int inc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 0; i < 32000; i += 4) {
        a[i * inc] += b[i];
        a[i * inc + 1] += b[i + 1];
        a[i * inc + 2] += b[i + 2];
        a[i * inc + 3] += b[i + 3];
    }
}
}
