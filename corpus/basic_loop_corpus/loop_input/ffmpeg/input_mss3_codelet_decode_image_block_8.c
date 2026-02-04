#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int vec[4];

void init_vars() {
    i = 0;
    for (int j = 0; j < 4; j++) {
        vec[j] = 0;
    }
}