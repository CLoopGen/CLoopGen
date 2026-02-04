#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int f[12];
int max;
int i;

void init_vars() {
    for (int idx = 0; idx < 12; idx++) {
        f[idx] = rand() % 200 - 100;
    }
    max = 0;
    i = 0;
}