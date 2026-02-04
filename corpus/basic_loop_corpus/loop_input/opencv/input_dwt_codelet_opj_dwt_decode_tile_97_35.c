#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float OPJ_FLOAT32;

typedef union {
    OPJ_FLOAT32 f[8];
} opj_v8_t;

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;
typedef size_t OPJ_SIZE_T;

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

opj_v8dwt_t h;
OPJ_UINT32 rw = 512;
OPJ_UINT32 rh = 512;
OPJ_UINT32 w = 1024;
OPJ_FLOAT32 *restrict aj;
OPJ_UINT32 j = 0;
OPJ_UINT32 k;

void init_vars() {
    aj = (OPJ_FLOAT32*)calloc(w * rh, sizeof(OPJ_FLOAT32));
    h.wavelet = (opj_v8_t*)calloc(rw, sizeof(opj_v8_t));
    
    for (OPJ_UINT32 i = 0; i < rw; i++) {
        for (int f = 0; f < 8; f++) {
            h.wavelet[i].f[f] = (OPJ_FLOAT32)(i + f * 0.1);
        }
    }
}