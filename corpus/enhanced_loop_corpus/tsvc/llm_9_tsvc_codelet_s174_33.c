#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int M;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 20 * 100000; nl++) {
    for (int i = 0; i < M; i++) {
        a[i + M] = a[i] + b[i] * 2.0f - a[i] * 0.5f;
    }
}
}
