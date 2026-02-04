#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG i;
BLASLONG ii;
float *ao1;
float *ao2;
float *ao3;
float *ao4;
float *ao5;
float *ao6;

static float b_data[6 * 10000];
static float ao1_data[10000 * 6];
static float ao2_data[10000 * 6];
static float ao3_data[10000 * 6];
static float ao4_data[10000 * 6];
static float ao5_data[10000 * 6];
static float ao6_data[10000 * 6];

void init_vars() {
    lda = 6;
    i = 10000;
    b = b_data;
    ao1 = ao1_data;
    ao2 = ao2_data;
    ao3 = ao3_data;
    ao4 = ao4_data;
    ao5 = ao5_data;
    ao6 = ao6_data;

    for (int j = 0; j < 10000 * 6; j++) {
        ao1_data[j] = 1.0f;
        ao2_data[j] = 2.0f;
        ao3_data[j] = 3.0f;
        ao4_data[j] = 4.0f;
        ao5_data[j] = 5.0f;
        ao6_data[j] = 6.0f;
    }

    for (int j = 0; j < 6 * 10000; j++) {
        b_data[j] = 0.0f;
    }
}