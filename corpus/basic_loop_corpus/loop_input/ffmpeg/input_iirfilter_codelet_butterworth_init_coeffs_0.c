#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct FFIIRFilterCoeffs {
    int order;
    float gain;
    int *cx;
    float *cy;
};

static struct FFIIRFilterCoeffs filter_coeffs;
static int data_order;
static int loop_i;

struct FFIIRFilterCoeffs *c = &filter_coeffs;
int order = 0;
int i = 0;

void init_vars() {
    order = 8192;
    data_order = order;
    
    filter_coeffs.order = data_order;
    filter_coeffs.gain = 1.0f;
    
    // Allocate cx array with (order >> 1) + 2 elements to prevent out-of-bounds access
    // We need indices from 0 to (order >> 1) inclusive
    int cx_size = (data_order >> 1) + 2;
    filter_coeffs.cx = (int*)calloc(cx_size, sizeof(int));
    
    // Allocate cy array with same size for completeness
    filter_coeffs.cy = (float*)calloc(cx_size, sizeof(float));
    
    // Initialize first element
    if (cx_size > 0) {
        filter_coeffs.cx[0] = 1;
    }
}