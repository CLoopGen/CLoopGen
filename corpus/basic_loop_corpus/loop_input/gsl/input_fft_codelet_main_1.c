#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double data[256];

void init_vars() {
    for (int j = 0; j < 256; j++) {
        data[j] = 0.0;
    }
    i = 0;
}