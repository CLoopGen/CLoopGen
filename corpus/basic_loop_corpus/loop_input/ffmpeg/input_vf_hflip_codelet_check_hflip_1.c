#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int step = 42;
int i = 0;
int step_array[4] = {0};

void init_vars() {
    step = 1000;
    for (int j = 0; j < 4; j++) {
        step_array[j] = 0;
    }
}