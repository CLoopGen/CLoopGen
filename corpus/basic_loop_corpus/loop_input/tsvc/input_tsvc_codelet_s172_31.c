#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
int n1;
int n3;

void init_vars() {
    n1 = 1;
    n3 = 1;

    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f;
        b[i] = 2.0f;
    }
}