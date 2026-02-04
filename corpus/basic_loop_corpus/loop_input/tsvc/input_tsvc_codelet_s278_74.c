#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];
__attribute__((aligned(64))) real_t e[32000];

void init_vars() {
    const int size = 32000;
    unsigned seed = (unsigned)time(NULL);
    
    for (int i = 0; i < size; i++) {
        a[i] = (real_t)((rand_r(&seed) % 200) - 100) / 100.0f;
        b[i] = (real_t)((rand_r(&seed) % 200) - 100) / 100.0f;
        c[i] = (real_t)((rand_r(&seed) % 200) - 100) / 100.0f;
        d[i] = (real_t)((rand_r(&seed) % 200) - 100) / 100.0f;
        e[i] = (real_t)((rand_r(&seed) % 200) - 100) / 100.0f;
    }
}