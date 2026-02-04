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

static float b_array[6 * 100000];
static float ao1_array[100000];
static float ao2_array[100000];
static float ao3_array[100000];
static float ao4_array[100000];
static float ao5_array[100000];
static float ao6_array[100000];

void init_vars() {
    b = b_array;
    ao1 = ao1_array;
    ao2 = ao2_array;
    ao3 = ao3_array;
    ao4 = ao4_array;
    ao5 = ao5_array;
    ao6 = ao6_array;

    for (int i = 0; i < 100000; i++) {
        ao1_array[i] = 1.0f;
        ao2_array[i] = 2.0f;
        ao3_array[i] = 3.0f;
        ao4_array[i] = 4.0f;
        ao5_array[i] = 5.0f;
        ao6_array[i] = 6.0f;
    }

    for (int i = 0; i < 6 * 100000; i++) {
        b_array[i] = 0.0f;
    }
}