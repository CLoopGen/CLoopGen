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
    const BLASLONG vector_size = 8;
    const BLASLONG total_elements_per_array = 32 * 1024 * 1024; // ~128MB per array, adjust for performance
    const BLASLONG total_iterations = total_elements_per_array / vector_size;

    b_data = (float*)calloc(total_elements_per_array, sizeof(float));
    a01_data = (float*)calloc(total_elements_per_array, sizeof(float));
    a02_data = (float*)calloc(total_elements_per_array, sizeof(float));
    a03_data = (float*)calloc(total_elements_per_array, sizeof(float));
    a04_data = (float*)calloc(total_elements_per_array, sizeof(float));
    a05_data = (float*)calloc(total_elements_per_array, sizeof(float));
    a06_data = (float*)calloc(total_elements_per_array, sizeof(float));
    a07_data = (float*)calloc(total_elements_per_array, sizeof(float));
    a08_data = (float*)calloc(total_elements_per_array, sizeof(float));

    b = b_data;
    a01 = a01_data;
    a02 = a02_data;
    a03 = a03_data;
    a04 = a04_data;
    a05 = a05_data;
    a06 = a06_data;
    a07 = a07_data;
    a08 = a08_data;
    i = total_iterations;
}