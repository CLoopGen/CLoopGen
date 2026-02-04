#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *in;
int i;

static float in_data[18];

void init_vars() {
    in = in_data;
    for (int j = 0; j < 18; j++) {
        in[j] = (float)(j + 1) * 1.5f;
    }
}