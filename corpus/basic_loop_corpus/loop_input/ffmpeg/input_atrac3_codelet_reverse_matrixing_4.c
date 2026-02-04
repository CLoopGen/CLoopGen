#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float matrix_coeffs[8] = {1.0f, 0.5f, 0.25f, 0.75f, 1.5f, 0.8f, 0.4f, 1.2f};

float *su1;
float *su2;
int *prev_code;
int *curr_code;

int i;
int nsample;
int band;

float mc1_l;
float mc1_r;
float mc2_l;
float mc2_r;

void init_vars() {
    const int num_bands = 4;
    const int samples_per_band = 256;
    const int total_samples = num_bands * samples_per_band;
    const int code_length = num_bands;

    su1 = (float*)aligned_alloc(32, total_samples * sizeof(float));
    su2 = (float*)aligned_alloc(32, total_samples * sizeof(float));
    prev_code = (int*)aligned_alloc(32, code_length * sizeof(int));
    curr_code = (int*)aligned_alloc(32, code_length * sizeof(int));

    for (int i = 0; i < total_samples; i++) {
        su1[i] = (float)(i % 128) * 0.01f;
        su2[i] = (float)(i % 64) * 0.02f;
    }

    for (int i = 0; i < code_length; i++) {
        prev_code[i] = i % 4;
        curr_code[i] = (i + 1) % 4;
    }

    i = 0;
    nsample = 0;
    band = 0;
    mc1_l = 0.0f;
    mc1_r = 0.0f;
    mc2_l = 0.0f;
    mc2_r = 0.0f;
}