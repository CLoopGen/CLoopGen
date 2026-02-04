#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

real_t arr[32000];
real_t ret;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        arr[i] = 1.0f;
    }
    ret = 0.0f;
}