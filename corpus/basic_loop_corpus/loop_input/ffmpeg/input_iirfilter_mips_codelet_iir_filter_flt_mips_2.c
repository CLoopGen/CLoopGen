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

struct FFIIRFilterState {
    float x[1];
};

static struct FFIIRFilterCoeffs coeffs;
static struct FFIIRFilterState *state;
static float *src_data;
static float *dst_data;

struct FFIIRFilterCoeffs *c = &coeffs;
struct FFIIRFilterState *s = NULL;
int size;
ptrdiff_t sstep;
ptrdiff_t dstep;
int i;
float *src0;
float *dst0;

void init_vars() {
    // Set filter order to 16 for reasonable computation load
    coeffs.order = 16;
    coeffs.gain = 0.5f;
    
    // Allocate coefficient arrays
    coeffs.cx = (int*)calloc(coeffs.order, sizeof(int));
    coeffs.cy = (float*)calloc(coeffs.order, sizeof(float));
    
    // Initialize coefficients
    for (int j = 0; j < coeffs.order; j++) {
        coeffs.cy[j] = (float)(j + 1) * 0.1f;
    }
    for (int j = 0; j < coeffs.order; j++) {
        coeffs.cx[j] = j + 1;
    }
    
    // Allocate filter state with padding for x array
    size_t state_size = offsetof(struct FFIIRFilterState, x) + coeffs.order * sizeof(float);
    state = (struct FFIIRFilterState*)calloc(1, state_size);
    s = state;
    
    // Initialize state memory
    for (int j = 0; j < coeffs.order; j++) {
        s->x[j] = (float)(j % 3) * 0.2f;
    }
    
    // Determine data size based on performance target (~0.01 sec)
    // Each iteration does O(order) work, so we scale accordingly
    size = 4 * 1024 * 1024; // ~4M iterations for good timing
    
    // Allocate input and output data
    src_data = (float*)malloc(size * sizeof(float));
    dst_data = (float*)malloc(size * sizeof(float));
    
    // Initialize source data
    for (int i = 0; i < size; i++) {
        src_data[i] = (float)(i % 100) * 0.01f;
    }
    
    // Set up step sizes (simple contiguous access)
    sstep = 1;
    dstep = 1;
    
    // Initialize pointers
    src0 = src_data;
    dst0 = dst_data;
}