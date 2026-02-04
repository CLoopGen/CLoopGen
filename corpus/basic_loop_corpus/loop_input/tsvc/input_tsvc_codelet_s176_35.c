#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
int m;

void init_vars() {
    m = 16000;
    
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f;
        b[i] = 2.0f;
        if (i < 16000) {
            c[i] = 3.0f;
        } else {
            c[i] = 0.0f;
        }
    }
}