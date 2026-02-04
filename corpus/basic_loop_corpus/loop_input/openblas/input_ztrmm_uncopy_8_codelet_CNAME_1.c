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
float *ao7;
float *ao8;

static float *b_storage;
static float *ao1_storage;
static float *ao2_storage;
static float *ao3_storage;
static float *ao4_storage;
static float *ao5_storage;
static float *ao6_storage;
static float *ao7_storage;
static float *ao8_storage;

void init_vars() {
    const BLASLONG iterations = 10000000; // Adjust to target ~0.01 sec runtime

    b_storage     = (float*)calloc(16 * iterations, sizeof(float));
    ao1_storage   = (float*)calloc(2 * iterations, sizeof(float));
    ao2_storage   = (float*)calloc(2 * iterations, sizeof(float));
    ao3_storage   = (float*)calloc(2 * iterations, sizeof(float));
    ao4_storage   = (float*)calloc(2 * iterations, sizeof(float));
    ao5_storage   = (float*)calloc(2 * iterations, sizeof(float));
    ao6_storage   = (float*)calloc(2 * iterations, sizeof(float));
    ao7_storage   = (float*)calloc(2 * iterations, sizeof(float));
    ao8_storage   = (float*)calloc(2 * iterations, sizeof(float));

    b   = b_storage;
    ao1 = ao1_storage;
    ao2 = ao2_storage;
    ao3 = ao3_storage;
    ao4 = ao4_storage;
    ao5 = ao5_storage;
    ao6 = ao6_storage;
    ao7 = ao7_storage;
    ao8 = ao8_storage;

    i = iterations;

    for (BLASLONG j = 0; j < 2 * iterations; j++) {
        ao1_storage[j] = 1.0f;
        ao2_storage[j] = 2.0f;
        ao3_storage[j] = 3.0f;
        ao4_storage[j] = 4.0f;
        ao5_storage[j] = 5.0f;
        ao6_storage[j] = 6.0f;
        ao7_storage[j] = 7.0f;
        ao8_storage[j] = 8.0f;
    }
}