#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int m;
int n = 256;
double res[256];

void init_vars() {
    for (int i = 0; i < 256; i++) {
        res[i] = 1.0 * (i + 1);
    }
}