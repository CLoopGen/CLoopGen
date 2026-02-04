#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

float *b;
BLASLONG i;
BLASLONG ii;
float *a01;
float *a02;
float *a03;
float *a04;
float *a05;
float *a06;
float *a07;
float *a08;

static float *b_data;
static float *a01_data;
static float *a02_data;
static float *a03_data;
static float *a04_data;
static float *a05_data;
static float *a06_data;
static float *a07_data;
static float *a08_data;

void init_vars() {
    const BLASLONG total_elements = 16 * 1048576; // ~64 MB of float data (approx 256MB total), adjust as needed
    const BLASLONG a_size_per = total_elements / 8; // Each aXX gets 1/8th of total elements
    const BLASLONG b_size = total_elements;

    b_data = (float *)malloc(b_size * sizeof(float));
    a01_data = (float *)malloc(a_size_per * sizeof(float));
    a02_data = (float *)malloc(a_size_per * sizeof(float));
    a03_data = (float *)malloc(a_size_per * sizeof(float));
    a04_data = (float *)malloc(a_size_per * sizeof(float));
    a05_data = (float *)malloc(a_size_per * sizeof(float));
    a06_data = (float *)malloc(a_size_per * sizeof(float));
    a07_data = (float *)malloc(a_size_per * sizeof(float));
    a08_data = (float *)malloc(a_size_per * sizeof(float));

    b = b_data;
    a01 = a01_data;
    a02 = a02_data;
    a03 = a03_data;
    a04 = a04_data;
    a05 = a05_data;
    a06 = a06_data;
    a07 = a07_data;
    a08 = a08_data;

    i = a_size_per / 2;

    for (BLASLONG j = 0; j < a_size_per; j++) {
        a01_data[j] = 1.0f;
        a02_data[j] = 2.0f;
        a03_data[j] = 3.0f;
        a04_data[j] = 4.0f;
        a05_data[j] = 5.0f;
        a06_data[j] = 6.0f;
        a07_data[j] = 7.0f;
        a08_data[j] = 8.0f;
    }

    for (BLASLONG j = 0; j < b_size; j++) {
        b_data[j] = 0.0f;
    }
}