#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

float *dx;
BLASLONG incx;
float *dy;
BLASLONG incy;
BLASLONG i__2;
BLASLONG i__;
float w;
float z__;
BLASLONG kx;
BLASLONG ky;
float dh11;
float dh12;
float dh22;
float dh21;

#define DATA_SIZE_MB 64
#define ARRAY_FLOAT_COUNT (DATA_SIZE_MB * (1 << 20) / sizeof(float))

static float dx_buffer[ARRAY_FLOAT_COUNT];
static float dy_buffer[ARRAY_FLOAT_COUNT];

void init_vars() {
    incx = 1;
    incy = 1;
    i__2 = ARRAY_FLOAT_COUNT;
    kx = 0;
    ky = 0;
    dh11 = 1.5f;
    dh12 = 0.5f;
    dh21 = -0.3f;
    dh22 = 2.0f;
    w = 0.0f;
    z__ = 0.0f;

    dx = dx_buffer;
    dy = dy_buffer;

    for (BLASLONG i = 0; i < ARRAY_FLOAT_COUNT; ++i) {
        dx[i] = (float)(i + 1);
        dy[i] = (float)(-(i + 1));
    }
}