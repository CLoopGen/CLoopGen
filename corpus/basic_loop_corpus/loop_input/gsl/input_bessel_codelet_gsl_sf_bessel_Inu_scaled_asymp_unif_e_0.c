#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double t;
double tpow[16];

void init_vars() {
    t = 2.0;
    tpow[0] = 1.0;
    for (int j = 1; j < 16; j++) {
        tpow[j] = 0.0;
    }
}