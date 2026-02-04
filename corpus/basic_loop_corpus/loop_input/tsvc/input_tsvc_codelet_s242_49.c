#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
real_t s1;
real_t s2;

void init_vars() {
    s1 = 1.5f;
    s2 = 2.5f;
    
    for (int i = 0; i < 32000; i++) {
        b[i] = (real_t)(i % 100) * 0.1f;
        c[i] = (real_t)(i % 200) * 0.2f;
        d[i] = (real_t)(i % 300) * 0.3f;
        a[i] = (real_t)(i % 400) * 0.4f;
    }
}