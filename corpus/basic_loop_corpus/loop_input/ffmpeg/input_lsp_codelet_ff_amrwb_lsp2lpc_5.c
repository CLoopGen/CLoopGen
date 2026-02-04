#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

double *lsp;
float *lp;
int lp_order;
int lp_half_order;
double pa[11];
double *qa;
int i;
int j;

#define DATA_SIZE_MB 64
#define TOTAL_SIZE (DATA_SIZE_MB * 1024 * 1024)

static double internal_lsp[TOTAL_SIZE / sizeof(double)];
static float internal_lp[TOTAL_SIZE / sizeof(float)];
static double internal_qa[11];

void init_vars() {
    lp_order = 10;
    lp_half_order = lp_order / 2;

    lsp = internal_lsp;
    lp = internal_lp;
    qa = internal_qa;

    for (int idx = 0; idx < 11; idx++) {
        pa[idx] = sin(idx + 1);
        if (idx < 11) {
            internal_qa[idx] = cos(idx + 1);
        }
    }

    for (int idx = 0; idx < TOTAL_SIZE / sizeof(double); idx++) {
        internal_lsp[idx] = 0.1 + (idx % 90) * 0.01;
    }

    for (int idx = 0; idx < TOTAL_SIZE / sizeof(float); idx++) {
        internal_lp[idx] = 0.0f;
    }

    i = 0;
    j = 0;
}