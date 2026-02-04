#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

float *delta_h;
float *delta_o;
float *hidden;
float **who;
int nh;
int no;
int j;
int k;
float h;
float sum;
float errsum;

void init_vars() {
    nh = 2048;
    no = 256;

    delta_h = (float*)aligned_alloc(32, (nh + 1) * sizeof(float));
    delta_o = (float*)aligned_alloc(32, (no + 1) * sizeof(float));
    hidden = (float*)aligned_alloc(32, (nh + 1) * sizeof(float));
    who = (float**)aligned_alloc(32, (nh + 1) * sizeof(float*));

    for (int i = 1; i <= nh; i++) {
        who[i] = (float*)aligned_alloc(32, (no + 1) * sizeof(float));
        for (int k = 1; k <= no; k++) {
            who[i][k] = (float)(rand()) / RAND_MAX * 0.2f - 0.1f;
        }
        delta_h[i] = 0.0f;
        hidden[i] = (float)(rand()) / RAND_MAX;
    }

    for (int k = 1; k <= no; k++) {
        delta_o[k] = (float)(rand()) / RAND_MAX * 0.4f - 0.2f;
    }

    h = 0.0f;
    sum = 0.0f;
    errsum = 0.0f;
}