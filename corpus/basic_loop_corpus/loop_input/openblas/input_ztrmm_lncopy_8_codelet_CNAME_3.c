#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG i;
BLASLONG ii;
float *ao1;
float *ao2;
float *ao3;
float *ao4;

static float b_data[8 * 16777216]; // ~64 MB for b
static float ao1_data[2 * 16777216]; // ~16 MB for ao1
static float ao2_data[2 * 16777216]; // ~16 MB for ao2
static float ao3_data[2 * 16777216]; // ~16 MB for ao3
static float ao4_data[2 * 16777216]; // ~16 MB for ao4

void init_vars() {
    b = b_data;
    ao1 = ao1_data;
    ao2 = ao2_data;
    ao3 = ao3_data;
    ao4 = ao4_data;
    i = 16777216; // ensures loop runs ~16.7M iterations, approx 0.01 sec on modern CPU

    for (int j = 0; j < 2 * 16777216; j++) {
        ao1_data[j] = (float)(j + 1);
        ao2_data[j] = (float)(j + 2);
        ao3_data[j] = (float)(j + 3);
        ao4_data[j] = (float)(j + 4);
    }

    for (int j = 0; j < 8 * 16777216; j++) {
        b_data[j] = 0.0f;
    }
}