#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double f[100];

void init_vars() {
    i = 0;
    for (int j = 0; j < 100; j++) {
        f[j] = 0.0;
    }
}