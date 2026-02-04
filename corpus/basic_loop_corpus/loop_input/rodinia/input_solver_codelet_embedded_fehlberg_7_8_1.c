#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *initvalu;
float h2_7;
float *initvalu_temp;
float **finavalu_temp;
int i;

#define ARRAY_SIZE 91
#define DATA_SIZE (1 << 20) // ~1MB of data for workload

static float initvalu_data[ARRAY_SIZE];
static float initvalu_temp_data[ARRAY_SIZE];
static float finavalu_temp_data[ARRAY_SIZE];

void init_vars() {
    h2_7 = 0.5f;

    initvalu = initvalu_data;
    initvalu_temp = initvalu_temp_data;

    finavalu_temp = malloc(sizeof(float*));
    finavalu_temp[0] = finavalu_temp_data;

    for (i = 0; i < ARRAY_SIZE; i++) {
        initvalu[i] = 1.0f + i * 0.1f;
        finavalu_temp[0][i] = 2.0f + i * 0.05f;
    }
}