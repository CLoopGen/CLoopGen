#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
int mid;

void init_vars() {
    mid = 16000;
    
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f + i * 0.0001f;
        b[i] = 2.0f + i * 0.0002f;
        c[i] = 0.5f;
        d[i] = 1.5f;
    }
}