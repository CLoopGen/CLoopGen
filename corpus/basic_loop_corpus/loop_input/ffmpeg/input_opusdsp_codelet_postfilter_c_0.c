#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *data;
int period;
int len;
float g0;
float g1;
float g2;
float x4;
float x3;
float x2;
float x1;

void init_vars() {
    len = 64 * 1024 * 1024; // 64M elements to target ~0.01 sec on modern CPU
    period = 4; // ensure period is small enough to allow negative indexing from i=0 safely

    // Allocate data with padding for negative indexing: need up to -(period-2) at i=0 -> index -period+2
    int offset = period - 2;
    float *aligned_data = (float*)calloc(len + offset, sizeof(float));
    data = aligned_data + offset; // point to base such that data[-offset] is valid

    // Initialize coefficients
    g0 = 0.1f;
    g1 = 0.2f;
    g2 = 0.3f;

    // Initialize shift register state
    x4 = 1.0f;
    x3 = 0.9f;
    x2 = 0.8f;
    x1 = 0.7f;
}