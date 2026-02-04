#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float amb_temp = 25.0f;

float *pIn;
float *tIn;
float *tOut;

int nx = 128;
int ny = 128;
int nz = 128;

float Cap = 1.2f;
float dt = 0.01f;
float ce = 0.1f;
float cw = 0.1f;
float cn = 0.1f;
float cs = 0.1f;
float ct = 0.1f;
float cb = 0.1f;
float cc = 0.4f;

int c;
int w;
int e;
int n;
int s;
int b;
int t;
int x;
int y;
int z;

void init_vars() {
    size_t total_size = nx * ny * nz;
    
    pIn = (float*)aligned_alloc(32, total_size * sizeof(float));
    tIn = (float*)aligned_alloc(32, total_size * sizeof(float));
    tOut = (float*)aligned_alloc(32, total_size * sizeof(float));

    for (size_t i = 0; i < total_size; i++) {
        pIn[i] = (float)(i % 100) * 0.5f;
        tIn[i] = 20.0f + (float)(i % 50) * 0.2f;
        tOut[i] = 0.0f;
    }

    amb_temp = 25.0f;
    Cap = 1.2f;
    dt = 0.01f;
    ce = 0.1f; cw = 0.1f; cn = 0.1f; cs = 0.1f; ct = 0.1f; cb = 0.1f; cc = 0.4f;

    c = w = e = n = s = b = t = x = y = z = 0;
}