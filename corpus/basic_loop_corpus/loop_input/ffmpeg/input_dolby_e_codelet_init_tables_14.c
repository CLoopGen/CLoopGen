#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float start_window[192];
__attribute__((aligned(32))) float window[3712];
int i;

void init_vars() {
    for (int j = 0; j < 192; j++) {
        start_window[j] = (float)(j % 128);
    }
    for (int j = 0; j < 3712; j++) {
        window[j] = 0.0f;
    }
    i = 0;
}