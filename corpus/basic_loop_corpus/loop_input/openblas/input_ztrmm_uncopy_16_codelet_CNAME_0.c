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

static float b_data[1048576]; // ~4MB buffer for b (1048576 floats)
static float a_data[32768];   // ~128KB buffer for each aXX (shared base)

void init_vars() {
    const int total_iterations = 16;
    const int elements_per_iter = 32;
    const int a_stride = 2;
    const int a_total_needed = total_iterations * a_stride;

    b = b_data;
    
    a01 = a_data;
    a02 = a_data + a_total_needed;
    a03 = a_data + 2 * a_total_needed;
    a04 = a_data + 3 * a_total_needed;
    a05 = a_data + 4 * a_total_needed;
    a06 = a_data + 5 * a_total_needed;
    a07 = a_data + 6 * a_total_needed;
    a08 = a_data + 7 * a_total_needed;
    a09 = a_data + 8 * a_total_needed;
    a10 = a_data + 9 * a_total_needed;
    a11 = a_data + 10 * a_total_needed;
    a12 = a_data + 11 * a_total_needed;
    a13 = a_data + 12 * a_total_needed;
    a14 = a_data + 13 * a_total_needed;
    a15 = a_data + 14 * a_total_needed;
    a16 = a_data + 15 * a_total_needed;

    for (int i = 0; i < 16 * a_total_needed; i++) {
        a_data[i] = (float)(i * 1.0f);
    }

    for (int i = 0; i < 1048576; i++) {
        b_data[i] = 0.0f;
    }
}