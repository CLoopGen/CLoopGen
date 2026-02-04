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

typedef size_t OPJ_SIZE_T;

extern opj_v8dwt_t h;
extern OPJ_UINT32 rw;
extern OPJ_UINT32 rh;
extern OPJ_UINT32 w;
extern OPJ_FLOAT32 *restrict aj;
extern OPJ_UINT32 j;
extern OPJ_UINT32 k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 k_step = 2;
    for (k = 0; k < rw; k += k_step) {
        OPJ_UINT32 l;
        for (l = 0; l < rh - j; l++) {
            aj[k + (OPJ_SIZE_T)w * l] = h.wavelet[k].f[l];
            if (k + 1 < rw) {
                aj[(k + 1) + (OPJ_SIZE_T)w * l] = h.wavelet[k + 1].f[l];
            }
        }
    }
}
