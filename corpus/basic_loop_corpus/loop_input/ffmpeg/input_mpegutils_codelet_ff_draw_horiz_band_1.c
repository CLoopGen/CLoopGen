#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int offset[8];
int i;

void init_vars() {
    for (int j = 0; j < 8; j++) {
        offset[j] = j * 100;
    }
    i = 0;
}