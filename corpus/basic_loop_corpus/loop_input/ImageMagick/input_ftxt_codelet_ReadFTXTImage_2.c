#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
long double chVals[64];

void init_vars() {
    i = 0;
    for (int j = 0; j < 64; j++) {
        chVals[j] = 0.0L;
    }
}