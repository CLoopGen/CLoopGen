#include <stdio.h>

typedef long BLASLONG;

float *dx;
float *dy;
BLASLONG i__1;
BLASLONG i__2;
BLASLONG i__;
float w;
float z__;
float dh11;
float dh12;
float dh22;
float dh21;

static float dx_buffer[65536];
static float dy_buffer[65536];

void init_vars() {
    // Initialize scalar values
    dh11 = 1.5f;
    dh12 = 0.8f;
    dh21 = -0.4f;
    dh22 = 1.2f;
    
    // Set up loop bounds to operate over entire buffer
    i__1 = 65536;
    i__2 = 1;
    i__ = 1;  // Start at 1 (1-based indexing as per loop logic)
    
    // Initialize pointers to our buffers
    dx = dx_buffer;
    dy = dy_buffer;
    
    // Initialize array data to prevent undefined behavior
    for (int j = 0; j < 65536; j++) {
        dx[j] = (float)(j % 100) * 0.5f;
        dy[j] = (float)((j + 13) % 100) * 0.3f;
    }
}