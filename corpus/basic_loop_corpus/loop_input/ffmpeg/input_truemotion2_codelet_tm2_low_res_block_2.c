#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int deltas[16];

void init_vars() {
    i = 0;
    for (int j = 0; j < 16; j++) {
        deltas[j] = 0;
    }
}