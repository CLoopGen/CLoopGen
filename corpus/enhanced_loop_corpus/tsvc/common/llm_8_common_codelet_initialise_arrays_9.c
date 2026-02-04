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
for (int i = 0; i < 16000; i += 2) {
    a[i] = 1.0f + (real_t)i;
    if (i + 1 < 16000) a[i+1] = 1.0f + (real_t)(i+1);
    b[i] = 2.0f + (real_t)i * 3.0f;
    if (i + 1 < 16000) b[i+1] = 2.0f + (real_t)(i+1) * 3.0f;
    c[i] = 3.0f + (real_t)i * 5.0f;
    if (i + 1 < 16000) c[i+1] = 3.0f + (real_t)(i+1) * 5.0f;
}
}
