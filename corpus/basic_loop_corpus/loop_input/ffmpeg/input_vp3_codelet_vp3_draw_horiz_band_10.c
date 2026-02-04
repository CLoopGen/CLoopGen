#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int offset[8];

void init_vars() {
    i = 0;
    for (int j = 0; j < 8; j++) {
        offset[j] = j * 100;
    }
}