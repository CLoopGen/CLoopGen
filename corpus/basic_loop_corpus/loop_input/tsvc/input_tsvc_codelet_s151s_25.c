#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

real_t a[32000];
real_t b[32000];
int m;

void init_vars() {
    m = 1;
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i * 2);
        b[i] = (real_t)(i);
    }
}