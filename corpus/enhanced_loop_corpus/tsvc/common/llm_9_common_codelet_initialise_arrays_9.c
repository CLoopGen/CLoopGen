#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 32000; i++) {
    real_t idx = (real_t)i;
    a[i] = idx * idx + 1.0f;
    b[i] = idx * idx * idx + 2.0f;
    c[i] = (idx + 1.0f) * (idx + 2.0f) + 3.0f;
    d[i] = (idx * 4.0f) + (idx * idx * 2.0f) + 4.0f;
    e[i] = (idx * idx * idx * 0.5f) + (idx * 3.0f) + 5.0f;
}
}
