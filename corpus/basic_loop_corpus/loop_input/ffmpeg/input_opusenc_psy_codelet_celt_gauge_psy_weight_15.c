#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
float band_score[21];
float max_score;

void init_vars() {
    for (int j = 0; j < 21; j++) {
        band_score[j] = (float)(rand() % 1000) / 10.0f;
    }
    max_score = -__builtin_inff();
}