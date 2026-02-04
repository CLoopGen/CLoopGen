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

extern opj_v8dwt_t *restrict dwt;
extern OPJ_FLOAT32 *restrict a;
extern OPJ_UINT32 width;
extern OPJ_UINT32 remaining_height;
extern OPJ_FLOAT32 *restrict bi;
extern OPJ_UINT32 i;
extern OPJ_UINT32 k;
extern OPJ_UINT32 x0;
extern OPJ_UINT32 x1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 2; ++k) {
        if (remaining_height >= 8 && ((OPJ_SIZE_T)a & 15) == 0 && ((OPJ_SIZE_T)bi & 15) == 0) {
            OPJ_UINT32 j;
            OPJ_FLOAT32 *restrict dst;
            for (i = x0; i < x1; ++i) {
                j = i;
                dst = bi + i * 2 * 8;
                for (OPJ_UINT32 row = 0; row < 8; ++row) {
                    dst[row] = a[j];
                    if (row < 7) j += width;
                }
            }
        } else {
            OPJ_UINT32 j;
            OPJ_FLOAT32 *restrict dst;
            for (i = x0; i < x1; ++i) {
                j = i;
                dst = bi + i * 2 * 8;
                dst[0] = a[j];
                for (OPJ_UINT32 row = 1; row < remaining_height && row < 8; ++row) {
                    j += width;
                    dst[row] = a[j];
                }
            }
        }
        bi = (OPJ_FLOAT32 *)(dwt->wavelet + 1 - dwt->cas);
        a += dwt->sn;
        x0 = dwt->win_h_x0;
        x1 = dwt->win_h_x1;
    }
}
