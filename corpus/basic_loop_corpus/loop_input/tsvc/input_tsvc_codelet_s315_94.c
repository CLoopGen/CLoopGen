#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
real_t x;
real_t chksum;
int _usr_index;

void init_vars() {
    srand(time(NULL));
    for (int i = 0; i < 32000; ++i) {
        a[i] = (real_t)(rand() % 10000) / 10.0f;
    }
    x = 0.0f;
    _usr_index = 0;
    chksum = 0.0f;
}