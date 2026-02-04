#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG ii;
float *ao1;
float *ao2;
float *ao3;
float *ao4;

static float b_data[8 * 65536];
static float ao1_data[2 * 65536];
static float ao2_data[2 * 65536];
static float ao3_data[2 * 65536];
static float ao4_data[2 * 65536];

void init_vars() {
    b = b_data;
    ao1 = ao1_data;
    ao2 = ao2_data;
    ao3 = ao3_data;
    ao4 = ao4_data;

    for (int i = 0; i < 2 * 65536; i++) {
        ao1_data[i] = 1.0f;
        ao2_data[i] = 2.0f;
        ao3_data[i] = 3.0f;
        ao4_data[i] = 4.0f;
    }

    for (int i = 0; i < 8 * 65536; i++) {
        b_data[i] = 0.0f;
    }
}