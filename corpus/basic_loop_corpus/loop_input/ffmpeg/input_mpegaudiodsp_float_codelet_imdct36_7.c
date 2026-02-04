#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define ARRAY_SIZE 65536

float icos36[9] = {0.984807753f, 0.939692621f, 0.866025404f, 0.766044443f, 
                   0.642787610f, 0.5f, 0.342020143f, 0.173648178f, 0.0f};

float icos36h[9] = {0.996194698f, 0.961261696f, 0.891006524f, 0.788010754f,
                    0.656059029f, 0.5f, 0.321393805f, 0.139173101f, 0.0f};

float *out;
float *buf;
float *win;
int i;
int j;
float t0;
float t1;
float t2;
float t3;
float s0;
float s1;
float s2;
float s3;
float tmp[18];

void init_vars() {
    out = aligned_alloc(32, sizeof(float) * 32 * 18);
    buf = aligned_alloc(32, sizeof(float) * 64);
    win = aligned_alloc(32, sizeof(float) * 64);

    for (int idx = 0; idx < 32 * 18; idx++) {
        out[idx] = (float)(idx % 100) * 0.01f;
    }

    for (int idx = 0; idx < 64; idx++) {
        buf[idx] = (float)(idx % 200) * 0.02f;
        win[idx] = (float)(idx % 150) * 0.015f;
    }

    for (int idx = 0; idx < 18; idx++) {
        tmp[idx] = (float)(idx % 50) * 0.1f;
    }

    i = 0;
    j = 0;
    t0 = t1 = t2 = t3 = 0.0f;
    s0 = s1 = s2 = s3 = 0.0f;
}