#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

float *b;
BLASLONG i;
BLASLONG ii;
float *a01;
float *a02;
float *a03;
float *a04;

static float *b_storage;
static float *a01_storage;
static float *a02_storage;
static float *a03_storage;
static float *a04_storage;

void init_vars() {
    BLASLONG total_elements = 67108864; // ~256MB of floats (67M * 4 bytes)
    i = total_elements / 4;

    b_storage = (float*)calloc(total_elements, sizeof(float));
    a01_storage = (float*)calloc(total_elements, sizeof(float));
    a02_storage = (float*)calloc(total_elements, sizeof(float));
    a03_storage = (float*)calloc(total_elements, sizeof(float));
    a04_storage = (float*)calloc(total_elements, sizeof(float));

    b = b_storage;
    a01 = a01_storage;
    a02 = a02_storage;
    a03 = a03_storage;
    a04 = a04_storage;
}