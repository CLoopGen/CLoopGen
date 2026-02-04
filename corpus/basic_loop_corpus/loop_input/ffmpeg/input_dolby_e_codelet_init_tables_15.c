#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float short_window2[192];
__attribute__((aligned(32))) float window[3712];
int i;

void init_vars() {
    for (int j = 0; j < 192; j++) {
        short_window2[j] = (float)(j + 1);
    }
    for (int j = 0; j < 3712; j++) {
        window[j] = 0.0f;
    }
    i = 0;
}