#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

long x[199];
int j;
long ss;

void init_vars() {
    ss = 1L << 20;
    for (int i = 0; i < 199; i++) {
        x[i] = 0;
    }
    j = 0;
}