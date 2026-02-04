#include <stdio.h>

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

#define DATA_SIZE (64 << 20)  // ~256 MB of total float data

static float static_b[DATA_SIZE / sizeof(float)];
static float static_ao1[DATA_SIZE / sizeof(float)];
static float static_ao2[DATA_SIZE / sizeof(float)];
static float static_ao3[DATA_SIZE / sizeof(float)];
static float static_ao4[DATA_SIZE / sizeof(float)];
static float static_ao5[DATA_SIZE / sizeof(float)];
static float static_ao6[DATA_SIZE / sizeof(float)];

void init_vars() {
    b = static_b;
    ao1 = static_ao1;
    ao2 = static_ao2;
    ao3 = static_ao3;
    ao4 = static_ao4;
    ao5 = static_ao5;
    ao6 = static_ao6;

    i = DATA_SIZE / (6 * sizeof(float));

    for (BLASLONG j = 0; j < DATA_SIZE / sizeof(float); j++) {
        static_ao1[j] = 1.0f;
        static_ao2[j] = 2.0f;
        static_ao3[j] = 3.0f;
        static_ao4[j] = 4.0f;
        static_ao5[j] = 5.0f;
        static_ao6[j] = 6.0f;
        if (j < i * 6) {
            static_b[j] = 0.0f;
        }
    }
}