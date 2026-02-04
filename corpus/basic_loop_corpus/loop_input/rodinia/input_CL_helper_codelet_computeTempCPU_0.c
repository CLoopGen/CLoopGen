#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

float *pIn;
float *tIn;
float *tOut;
int nx;
int ny;
int nz;
float Cap;
float dt;
float amb_temp;
float ce;
float cw;
float cn;
float cs;
float ct;
float cb;
float cc;
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
    nx = 256;
    ny = 256;
    nz = 64;
    size_t num_elements = (size_t)nx * ny * nz;

    pIn = (float*)aligned_alloc(32, num_elements * sizeof(float));
    tIn = (float*)aligned_alloc(32, num_elements * sizeof(float));
    tOut = (float*)aligned_alloc(32, num_elements * sizeof(float));

    for (size_t i = 0; i < num_elements; i++) {
        pIn[i] = 1.0f + (i % 100) * 0.01f;
        tIn[i] = 300.0f + (i % 50) * 0.1f;
    }

    Cap = 1.2f;
    dt = 0.01f;
    amb_temp = 298.15f;
    ce = 0.1f;
    cw = 0.1f;
    cn = 0.1f;
    cs = 0.1f;
    ct = 0.1f;
    cb = 0.1f;
    cc = 0.4f;

    c = 0;
    w = 0;
    e = 0;
    n = 0;
    s = 0;
    b = 0;
    t = 0;
    x = 0;
    y = 0;
    z = 0;
}