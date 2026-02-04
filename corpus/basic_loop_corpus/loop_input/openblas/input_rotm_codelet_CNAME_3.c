#include <stdio.h>

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
float dh12;
float dh21;

#define DATA_SIZE (64 << 20) // 64 million elements, ~256MB for two arrays

static float dx_data[DATA_SIZE];
static float dy_data[DATA_SIZE];

void init_vars() {
    // Initialize array pointers
    dx = dx_data;
    dy = dy_data;

    // Initialize increments (typical values for unit stride)
    incx = 1;
    incy = 1;

    // Initialize loop bound to stay within allocated data
    i__2 = DATA_SIZE;

    // Initialize initial indices
    kx = 0;
    ky = 0;

    // Initialize constants for transformation
    dh12 = 0.75f;
    dh21 = 0.25f;

    // Initialize working variables
    w = 0.0f;
    z__ = 0.0f;
}