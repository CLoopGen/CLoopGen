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
float dh11;
float dh22;

static float dx_buffer[65536];
static float dy_buffer[65536];

void init_vars() {
    // Initialize scalar values
    dh11 = 0.98f;
    dh22 = 0.99f;
    incx = 1;
    incy = 1;
    
    // Set problem size to ensure ~0.01 seconds runtime
    // Assuming moderate CPU speed and simple arithmetic, aim for ~10M iterations
    i__2 = 65536;
    
    // Initialize buffer indices
    kx = 0;
    ky = 0;
    
    // Initialize array pointers to internal buffers
    dx = dx_buffer;
    dy = dy_buffer;
    
    // Initialize array contents to avoid undefined behavior
    for (BLASLONG i = 0; i < i__2; ++i) {
        dx[i] = (float)(i + 1) * 0.1f;
        dy[i] = (float)(i + 1) * 0.2f;
    }
}