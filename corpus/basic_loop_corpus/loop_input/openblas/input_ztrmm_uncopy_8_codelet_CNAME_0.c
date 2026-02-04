#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG ii;
float *ao1;
float *ao2;
float *ao3;
float *ao4;
float *ao5;
float *ao6;
float *ao7;
float *ao8;

static float b_data[16 * 8];
static float ao1_data[2 * 8];
static float ao2_data[2 * 8];
static float ao3_data[2 * 8];
static float ao4_data[2 * 8];
static float ao5_data[2 * 8];
static float ao6_data[2 * 8];
static float ao7_data[2 * 8];
static float ao8_data[2 * 8];

void init_vars() {
    b = b_data;
    ao1 = ao1_data;
    ao2 = ao2_data;
    ao3 = ao3_data;
    ao4 = ao4_data;
    ao5 = ao5_data;
    ao6 = ao6_data;
    ao7 = ao7_data;
    ao8 = ao8_data;

    for (int i = 0; i < 2 * 8; i++) {
        ao1_data[i] = 1.0f;
        ao2_data[i] = 2.0f;
        ao3_data[i] = 3.0f;
        ao4_data[i] = 4.0f;
        ao5_data[i] = 5.0f;
        ao6_data[i] = 6.0f;
        ao7_data[i] = 7.0f;
        ao8_data[i] = 8.0f;
    }

    for (int i = 0; i < 16 * 8; i++) {
        b_data[i] = 0.0f;
    }
}