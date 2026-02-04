#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef float OPJ_FLOAT32;
typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;
typedef size_t OPJ_SIZE_T;

typedef union {
    OPJ_FLOAT32 f[8];
} opj_v8_t;

typedef struct v8dwt_local {
    opj_v8_t *wavelet;
    OPJ_INT32 dn;
    OPJ_INT32 sn;
    OPJ_INT32 cas;
    OPJ_UINT32 win_l_x0;
    OPJ_UINT32 win_l_x1;
    OPJ_UINT32 win_h_x0;
    OPJ_UINT32 win_h_x1;
} opj_v8dwt_t;

opj_v8dwt_t *restrict dwt;
OPJ_FLOAT32 *restrict a;
OPJ_UINT32 width;
OPJ_UINT32 remaining_height;
OPJ_FLOAT32 *restrict bi;
OPJ_UINT32 i;
OPJ_UINT32 k;
OPJ_UINT32 x0;
OPJ_UINT32 x1;

static opj_v8_t *wavelet_mem;
static OPJ_FLOAT32 *a_mem;
static OPJ_FLOAT32 *bi_mem;

void init_vars() {
    // Allocate enough data to make loop run ~0.01 seconds
    // Based on typical modern CPU: aim for ~64-128MB of effective memory access
    width = 1024;
    remaining_height = 16;  // Must be >=8 to take fast path, but we also test slow path in practice
    x0 = 0;
    x1 = width / 2;  // Process half the row

    // Allocate wavelet buffer (needs at least 2 opj_v8_t elements)
    wavelet_mem = (opj_v8_t*)aligned_alloc(16, 2 * sizeof(opj_v8_t));
    if (!wavelet_mem) abort();
    memset(wavelet_mem, 0, 2 * sizeof(opj_v8_t));

    // Allocate input array 'a': treat as image with dimensions (remaining_height + padding) x width
    // We need up to j += width*7, so ensure sufficient vertical size
    OPJ_UINT32 total_height = remaining_height + 10;  // Add padding to avoid out-of-bounds
    a_mem = (OPJ_FLOAT32*)aligned_alloc(16, total_height * width * sizeof(OPJ_FLOAT32));
    if (!a_mem) abort();
    for (OPJ_UINT32 idx = 0; idx < total_height * width; ++idx) {
        a_mem[idx] = (OPJ_FLOAT32)(idx % 100) / 100.0f;
    }

    // Allocate bi buffer: each processed column writes 16 floats (i*2*8 -> 8 values)
    // Size: x1 * 16 floats
    bi_mem = (OPJ_FLOAT32*)aligned_alloc(16, x1 * 16 * sizeof(OPJ_FLOAT32));
    if (!bi_mem) abort();
    memset(bi_mem, 0, x1 * 16 * sizeof(OPJ_FLOAT32));

    // Allocate and initialize dwt structure
    dwt = (opj_v8dwt_t*)malloc(sizeof(opj_v8dwt_t));
    if (!dwt) abort();

    dwt->wavelet = wavelet_mem;
    dwt->dn = 8;
    dwt->sn = width;
    dwt->cas = 0;
    dwt->win_l_x0 = 0;
    dwt->win_l_x1 = x1;
    dwt->win_h_x0 = 0;
    dwt->win_h_x1 = x1;

    // Initialize primary variables
    a = a_mem;
    bi = bi_mem;
    i = 0;
    k = 0;
}