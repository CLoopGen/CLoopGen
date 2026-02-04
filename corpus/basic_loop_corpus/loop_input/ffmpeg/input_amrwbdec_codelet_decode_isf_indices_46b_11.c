#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t dico23_isf[128][3] = {0};

uint16_t ind_data[5] = {0};
uint16_t *ind = ind_data;

float isf_q_data[9] = {0.0f};
float *isf_q = isf_q_data;

int i = 0;

void init_vars() {
    for (int j = 0; j < 128; j++) {
        for (int k = 0; k < 3; k++) {
            dico23_isf[j][k] = (int16_t)(rand() % 65536 - 32768);
        }
    }

    for (int j = 0; j < 5; j++) {
        ind_data[j] = rand() % 128;
    }

    for (int j = 0; j < 9; j++) {
        isf_q_data[j] = (float)(rand() % 1000) / 100.0f;
    }

    i = 0;
}