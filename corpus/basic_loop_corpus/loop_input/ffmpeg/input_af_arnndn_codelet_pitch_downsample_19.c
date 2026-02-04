#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float tmp;
float lpc[4];

void init_vars() {
    tmp = 1.0f;
    for (int i = 0; i < 4; i++) {
        lpc[i] = 1.0f + i * 0.5f;
    }
}