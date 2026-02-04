#include <stdio.h>

typedef long BLASLONG;

float *dx;
float *dy;
BLASLONG i__1;
BLASLONG i__2;
BLASLONG i__;
float w;
float z__;
float dh12;
float dh21;

#define DATA_SIZE (64 << 20) // 64 MB of data

static float dx_buffer[DATA_SIZE / sizeof(float)];
static float dy_buffer[DATA_SIZE / sizeof(float)];

void init_vars() {
    dx = dx_buffer;
    dy = dy_buffer;
    i__1 = (DATA_SIZE / sizeof(float)) - 1;
    i__2 = 1;
    i__ = 1;
    dh12 = 1.5f;
    dh21 = 0.5f;
    w = 0.0f;
    z__ = 0.0f;

    for (BLASLONG j = 0; j <= i__1; ++j) {
        dx[j] = 1.0f + (float)j;
        dy[j] = 2.0f - (float)j;
    }
}