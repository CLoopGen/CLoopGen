#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 131072;

double b0 = 0.5;
double b1 = 0.25;
double b2 = 0.125;
double a1 = 0.2;
double a2 = 0.1;
int *clippings = NULL;
int disabled = 0;
int16_t *ibuf = NULL;
int16_t *obuf = NULL;
double i1 = 0.0;
double i2 = 0.0;
double o1 = 0.0;
double o2 = 0.0;
double wet = 0.8;
double dry = 0.2;
double out = 0.0;
int i = 0;

void init_vars() {
    clippings = (int*)calloc(1, sizeof(int));
    ibuf = (int16_t*)aligned_alloc(32, len * sizeof(int16_t));
    obuf = (int16_t*)aligned_alloc(32, len * sizeof(int16_t));

    for (int j = 0; j < len; j++) {
        ibuf[j] = (int16_t)(32767 * ((j % 2047) / 2047.0));
    }

    i1 = ibuf[0];
    i2 = ibuf[0];
    o1 = 0.0;
    o2 = 0.0;
    *clippings = 0;
}