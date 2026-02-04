#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 1 << 24; // Approximately 16.7 million iterations, ~0.01s on modern CPU

double b0 = 0.5;
double b1 = 0.25;
double b2 = 0.125;
double a1 = -0.3;
double a2 = 0.1;
int *clippings;
int disabled = 0;
float *ibuf;
float *obuf;
double i1 = 0.0;
double i2 = 0.0;
double o1 = 0.0;
double o2 = 0.0;
double wet = 0.8;
double dry = 0.2;
double out = 0.0;
int i = 0;

void init_vars() {
    ibuf = (float *)calloc(len, sizeof(float));
    obuf = (float *)calloc(len, sizeof(float));
    clippings = (int *)calloc(1, sizeof(int));

    if (!ibuf || !obuf || !clippings) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        ibuf[j] = (float)((j % 1000) - 500) / 500.0f;
    }
}