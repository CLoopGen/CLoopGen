#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int max_order = 32;
double ref[32];
int i;

void init_vars() {
    for (int j = 0; j < max_order; j++) {
        ref[j] = (double)(j * 10);
    }
}