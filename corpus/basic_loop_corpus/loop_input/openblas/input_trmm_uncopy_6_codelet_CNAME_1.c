#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

float *b;
BLASLONG i;
BLASLONG ii;
float *ao1;
float *ao2;
float *ao3;
float *ao4;
float *ao5;
float *ao6;

static float *b_storage;
static float *ao1_storage;
static float *ao2_storage;
static float *ao3_storage;
static float *ao4_storage;
static float *ao5_storage;
static float *ao6_storage;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(float))  // ~64 MB of floats

void init_vars() {
    b_storage = (float*)calloc(DATA_SIZE, sizeof(float));
    ao1_storage = (float*)calloc(DATA_SIZE, sizeof(float));
    ao2_storage = (float*)calloc(DATA_SIZE, sizeof(float));
    ao3_storage = (float*)calloc(DATA_SIZE, sizeof(float));
    ao4_storage = (float*)calloc(DATA_SIZE, sizeof(float));
    ao5_storage = (float*)calloc(DATA_SIZE, sizeof(float));
    ao6_storage = (float*)calloc(DATA_SIZE, sizeof(float));

    b = b_storage;
    ao1 = ao1_storage;
    ao2 = ao2_storage;
    ao3 = ao3_storage;
    ao4 = ao4_storage;
    ao5 = ao5_storage;
    ao6 = ao6_storage;

    i = DATA_SIZE / 6;  // Ensure we don't exceed bounds: each iteration writes 6 elements
}