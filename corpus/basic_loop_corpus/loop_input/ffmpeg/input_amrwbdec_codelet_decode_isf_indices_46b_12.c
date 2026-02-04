#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t dico24_isf[32][3] = {0};

uint16_t ind_data[6];
uint16_t *ind = ind_data;

float isf_q_data[12];
float *isf_q = isf_q_data;

int i;

void init_vars() {
    for (int j = 0; j < 32; j++) {
        for (int k = 0; k < 3; k++) {
            dico24_isf[j][k] = (int16_t)(rand() % 65535 - 32768);
        }
    }

    for (int j = 0; j < 6; j++) {
        ind_data[j] = rand() % 32;
    }

    for (int j = 0; j < 12; j++) {
        isf_q_data[j] = 1.0f * rand() / RAND_MAX;
    }

    i = 0;
}