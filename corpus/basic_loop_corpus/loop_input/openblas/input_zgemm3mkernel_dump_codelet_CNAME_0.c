#include <stdio.h>

typedef long BLASLONG;

BLASLONG bm;
BLASLONG bn;
BLASLONG bk;
float alphar;
float alphai;
float *ba;
float *bb;
float *C;
BLASLONG ldc;
BLASLONG i;
BLASLONG j;
BLASLONG k;
float *C0;
float *C1;
float *ptrba;
float *ptrbb;
float res0;
float res1;
float res2;
float res3;
float res4;
float res5;
float res6;
float res7;
float load0;
float load1;
float load2;
float load3;
float load4;
float load5;
float load6;
float load7;

static float *ba_data;
static float *bb_data;
static float *C_data;

void init_vars() {
    // Set matrix dimensions to ensure sufficient workload (~0.01 sec on modern CPU)
    bm = 1024;
    bn = 1024;
    bk = 512;
    alphar = 1.5f;
    alphai = 0.8f;
    ldc = 1024;

    // Allocate data with proper sizes to prevent out-of-bounds access
    // ba: bm x bk complex values (2 floats per element) -> size = bm * bk * 2
    // bb: bk x bn complex values (2x2 tile layout, but we access bk*bn blocks of 4 floats)
    // C:  ldc x bn complex values (2 floats per element), but accessed in 2x2 blocks

    const size_t ba_size = bm * bk * 2;
    const size_t bb_size = bk * bn * 4;  // each iteration uses 4 elements (2x2 complex)
    const size_t c_size = ldc * bn * 2;

    ba_data = (float*)__builtin_malloc(ba_size * sizeof(float));
    bb_data = (float*)__builtin_malloc(bb_size * sizeof(float));
    C_data   = (float*)__builtin_malloc(c_size * sizeof(float));

    if (!ba_data || !bb_data || !C_data) {
        __builtin_abort();
    }

    // Initialize all memory to zero to avoid NaNs and undefined behavior
    for (size_t idx = 0; idx < ba_size; ++idx) {
        ba_data[idx] = 0.0f;
    }
    for (size_t idx = 0; idx < bb_size; ++idx) {
        bb_data[idx] = 0.0f;
    }
    for (size_t idx = 0; idx < c_size; ++idx) {
        C_data[idx] = 0.0f;
    }

    // Assign pointers
    ba = ba_data;
    bb = bb_data;
    C = C_data;

    // Initialize working pointers to avoid undefined initial state
    C0 = C;
    C1 = C + 2 * ldc;
    ptrba = ba;
    ptrbb = bb;

    // Initialize accumulators
    res0 = res1 = res2 = res3 = res4 = res5 = res6 = res7 = 0.0f;
    load0 = load1 = load2 = load3 = load4 = load5 = load6 = load7 = 0.0f;
}