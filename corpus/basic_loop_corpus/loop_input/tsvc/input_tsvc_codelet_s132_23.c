#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t aa[256][256];

int j = 1;
int k = 0;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        b[i] = 1.0f + i * 0.001f;
        c[i] = 2.0f - i * 0.0005f;
    }
    
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            aa[i][j] = (i == 0 && j == 0) ? 0.0f : (real_t)(i * 256 + j);
        }
    }
    
    j = 1;
    k = 0;
}