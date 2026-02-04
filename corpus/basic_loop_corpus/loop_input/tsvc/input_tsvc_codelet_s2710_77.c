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
int x;

void init_vars() {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(rand() % 100) / 10.0f;
        b[i] = (real_t)(rand() % 100) / 10.0f;
        c[i] = (real_t)(rand() % 100) / 10.0f;
        d[i] = (real_t)(rand() % 100) / 10.0f;
        e[i] = (real_t)(rand() % 100) / 10.0f;
    }
    x = rand() % 2 ? 1 : -1;
}