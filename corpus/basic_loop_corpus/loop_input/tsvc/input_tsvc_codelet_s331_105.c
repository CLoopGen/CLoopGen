#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
int j;
real_t chksum;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i - 16000); // ensures some negative values
    }
    j = 0;
    chksum = 0.0f;
}