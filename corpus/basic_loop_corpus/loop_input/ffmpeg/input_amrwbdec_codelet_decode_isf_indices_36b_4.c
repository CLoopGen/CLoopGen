#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE_2D 128
#define INNER_SIZE 5
#define DATA_SCALE (1 << 15)

static int16_t dico21_isf_36b_data[ARRAY_SIZE_2D][INNER_SIZE];
static uint16_t ind_data[3];
static float isf_q_data[INNER_SIZE];

int16_t (*dico21_isf_36b)[INNER_SIZE] = dico21_isf_36b_data;
uint16_t *ind = ind_data;
float *isf_q = isf_q_data;
int i;

void init_vars() {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < ARRAY_SIZE_2D; i++) {
        for (int j = 0; j < INNER_SIZE; j++) {
            dico21_isf_36b_data[i][j] = (int16_t)(rand() % 65536 - 32768);
        }
    }

    for (int i = 0; i < 3; i++) {
        ind_data[i] = (uint16_t)(rand() % ARRAY_SIZE_2D);
    }

    for (int i = 0; i < INNER_SIZE; i++) {
        isf_q_data[i] = (float)(rand()) / RAND_MAX * 100.0f;
    }
}