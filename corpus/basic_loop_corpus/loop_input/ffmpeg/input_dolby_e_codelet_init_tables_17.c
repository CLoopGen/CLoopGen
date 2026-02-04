#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float short_window3[64] = {0};

__attribute__((aligned(32))) float window[3712] = {0};

int i;

void init_vars() {
    for (int j = 0; j < 64; j++) {
        short_window3[j] = (float)(j + 1);
    }
    for (int j = 0; j < 3712; j++) {
        window[j] = 0.0f;
    }
}