#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

long x[199];
int j;

void init_vars() {
    j = 0;
    for (int i = 0; i < 199; i++) {
        x[i] = 0xdeadbeef;
    }
}