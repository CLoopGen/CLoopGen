#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int alphas[256];
int n;

void init_vars() {
    for (int i = 0; i < 256; ++i) {
        alphas[i] = (i == 255) ? 1 : 0;
    }
    n = 0;
}