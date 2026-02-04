#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define LEN 1000
#define OUT_CH 32
#define IN_CH 32

float **samples;
float **matrix;
int len;
int out_ch;
int in_ch;
int i;
int in;
int out;
float temp[32];

void init_vars() {
    len = LEN;
    out_ch = OUT_CH;
    in_ch = IN_CH;

    samples = (float**)calloc(in_ch, sizeof(float*));
    for (int i = 0; i < in_ch; i++) {
        samples[i] = (float*)calloc(len, sizeof(float));
        for (int j = 0; j < len; j++) {
            samples[i][j] = (float)(i + j) / (in_ch + len);
        }
    }

    matrix = (float**)calloc(out_ch, sizeof(float*));
    for (int i = 0; i < out_ch; i++) {
        matrix[i] = (float*)calloc(in_ch, sizeof(float));
        for (int j = 0; j < in_ch; j++) {
            matrix[i][j] = (float)(i * in_ch + j) / (out_ch * in_ch);
        }
    }

    for (int i = 0; i < 32; i++) {
        temp[i] = 0.0f;
    }
}