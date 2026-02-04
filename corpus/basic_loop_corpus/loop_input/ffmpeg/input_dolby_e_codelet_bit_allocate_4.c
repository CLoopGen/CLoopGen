#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nb_exponent = 50;

int msk_val[50];

uint16_t *hearing_thresh;

int i;

void init_vars() {
    hearing_thresh = (uint16_t *)malloc(nb_exponent * sizeof(uint16_t));
    if (!hearing_thresh) {
        exit(1);
    }
    for (i = 0; i < nb_exponent; i++) {
        msk_val[i] = (i + 1) * 300;
        hearing_thresh[i] = (i + 1) * 200;
    }
}