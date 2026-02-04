#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float amb_temp;
float *pIn;
int nx;
int ny;
int nz;
float Cap;
float dt;
float ce;
float cw;
float cn;
float cs;
float ct;
float cb;
float cc;
float *tIn_t;
float *tOut_t;
int z;

void init_vars() {
    nx = 64;
    ny = 64;
    nz = 64;

    amb_temp = 25.0f;
    Cap = 1.0f;
    dt = 0.1f;
    ce = 0.1f;
    cw = 0.1f;
    cn = 0.1f;
    cs = 0.1f;
    ct = 0.1f;
    cb = 0.1f;
    cc = 0.4f;

    size_t total_size = nx * ny * nz;
    pIn = (float*)aligned_alloc(32, total_size * sizeof(float));
    tIn_t = (float*)aligned_alloc(32, total_size * sizeof(float));
    tOut_t = (float*)aligned_alloc(32, total_size * sizeof(float));

    for (size_t i = 0; i < total_size; i++) {
        pIn[i] = (float)(i % 100);
        tIn_t[i] = 20.0f + (float)(i % 50) * 0.1f;
        tOut_t[i] = 0.0f;
    }
}