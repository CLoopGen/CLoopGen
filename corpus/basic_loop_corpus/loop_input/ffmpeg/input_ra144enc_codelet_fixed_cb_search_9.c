#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

const int8_t ff_cb1_vects[128][40] = {0};
int *cb1_idx;
int i;
float vect[40];

void init_vars() {
    static int internal_cb1_idx = 64;
    cb1_idx = &internal_cb1_idx;

    for (int j = 0; j < 128; j++) {
        for (int k = 0; k < 40; k++) {
            ((int8_t(*)[40])ff_cb1_vects)[j][k] = (int8_t)(j * 40 + k - 50);
        }
    }

    for (int k = 0; k < 40; k++) {
        vect[k] = 0.0f;
    }

    i = 0;
}