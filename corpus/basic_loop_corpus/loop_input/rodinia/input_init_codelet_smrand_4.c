#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

long mrand_list[56];
int i;

void init_vars() {
    mrand_list[0] = 123456789L;
    for (int j = 1; j < 56; j++) {
        mrand_list[j] = 0L;
    }
    i = 1;
}