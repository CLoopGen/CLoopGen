#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *xcorr;
float *y;
int len;
int max_pitch;
int *best_pitch;
float best_num[2];
float best_den[2];
float Syy;

void init_vars() {
    len = 1024;
    max_pitch = 16384;
    size_t xcorr_size = max_pitch * sizeof(float);
    size_t y_size = (len + max_pitch) * sizeof(float);
    size_t best_pitch_size = 2 * sizeof(int);

    xcorr = (float *)malloc(xcorr_size);
    y = (float *)malloc(y_size);
    best_pitch = (int *)malloc(best_pitch_size);

    for (int i = 0; i < max_pitch; i++) {
        xcorr[i] = (float)(rand() % 2000 - 1000) * 1e12f;
    }

    for (int i = 0; i < len + max_pitch; i++) {
        y[i] = (float)(rand() % 2000 - 1000) / 1000.0f;
    }

    best_num[0] = 0.0f;
    best_num[1] = 0.0f;
    best_den[0] = 1.0f;
    best_den[1] = 1.0f;
    best_pitch[0] = 0;
    best_pitch[1] = 0;
    Syy = 1.0f;
}