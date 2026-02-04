#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG ii;

float *a01;
float *a02;
float *a03;
float *a04;
float *a05;
float *a06;
float *a07;
float *a08;
float *a09;
float *a10;
float *a11;
float *a12;
float *a13;
float *a14;
float *a15;
float *a16;

#define DATA_SIZE (64 << 20) / sizeof(float)  // ~64 MB of floats
#define ITERATIONS (DATA_SIZE / 16)

static float b_data[ITERATIONS * 16];
static float a_data[16][DATA_SIZE];

void init_vars() {
    b = b_data;

    a01 = a_data[0];
    a02 = a_data[1];
    a03 = a_data[2];
    a04 = a_data[3];
    a05 = a_data[4];
    a06 = a_data[5];
    a07 = a_data[6];
    a08 = a_data[7];
    a09 = a_data[8];
    a10 = a_data[9];
    a11 = a_data[10];
    a12 = a_data[11];
    a13 = a_data[12];
    a14 = a_data[13];
    a15 = a_data[14];
    a16 = a_data[15];

    for (int i = 0; i < 16; i++) {
        for (BLASLONG j = 0; j < DATA_SIZE; j++) {
            a_data[i][j] = (float)(i + 1) * (j % 251);
        }
    }

    for (BLASLONG j = 0; j < ITERATIONS * 16; j++) {
        b_data[j] = 0.0f;
    }
}