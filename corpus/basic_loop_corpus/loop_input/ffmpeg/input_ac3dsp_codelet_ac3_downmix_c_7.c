#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float **samples;
float **matrix;
int in_ch;
int len;
int i;
int j;
float v0;
float v1;

void init_vars() {
    len = 65536;    // ~256KB of float data per channel (65536 * sizeof(float) ≈ 256KB)
    in_ch = 8;      // 8 input channels

    // Allocate matrix: 2 rows, in_ch columns
    matrix = (float**)calloc(2, sizeof(float*));
    for (int row = 0; row < 2; row++) {
        matrix[row] = (float*)calloc(in_ch, sizeof(float));
        for (int col = 0; col < in_ch; col++) {
            matrix[row][col] = 1.0f / (row + col + 1); // Small non-zero values
        }
    }

    // Allocate samples: in_ch + 2 extra rows to safely access samples[0], samples[1]
    samples = (float**)calloc(in_ch + 2, sizeof(float*));
    for (int ch = 0; ch < in_ch + 2; ch++) {
        samples[ch] = (float*)calloc(len, sizeof(float));
        for (int pos = 0; pos < len; pos++) {
            samples[ch][pos] = rand() / (float)RAND_MAX; // Random initial values
        }
    }

    // Initialize scalars
    i = 0;
    j = 0;
    v0 = 0.0f;
    v1 = 0.0f;
}