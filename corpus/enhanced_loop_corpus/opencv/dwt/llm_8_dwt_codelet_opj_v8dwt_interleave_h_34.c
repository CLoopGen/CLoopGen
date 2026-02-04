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
for (k = 0; k < 4; ++k) {
    if (remaining_height >= 8 && ((OPJ_SIZE_T)a & 15) == 0 && ((OPJ_SIZE_T)bi & 15) == 0) {
        for (i = x0; i < x1; ++i) {
            OPJ_UINT32 j = i;
            OPJ_FLOAT32 *restrict dst = bi + i * 2 * 8;
            dst[0] = a[j];
            dst[1] = a[j + width];
            dst[2] = a[j + 2*width];
            dst[3] = a[j + 3*width];
            dst[4] = a[j + 4*width];
            dst[5] = a[j + 5*width];
            dst[6] = a[j + 6*width];
            dst[7] = a[j + 7*width];
        }
    } else {
        for (i = x0; i < x1; ++i) {
            OPJ_UINT32 j = i;
            OPJ_FLOAT32 *restrict dst = bi + i * 2 * 8;
            dst[0] = a[j];
            if (remaining_height > 1) {
                dst[1] = a[j + width];
                if (remaining_height > 2) {
                    dst[2] = a[j + 2*width];
                    if (remaining_height > 3) {
                        dst[3] = a[j + 3*width];
                        if (remaining_height > 4) {
                            dst[4] = a[j + 4*width];
                            if (remaining_height > 5) {
                                dst[5] = a[j + 5*width];
                                if (remaining_height > 6) {
                                    dst[6] = a[j + 6*width];
                                    if (remaining_height > 7) {
                                        dst[7] = a[j + 7*width];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    bi = (OPJ_FLOAT32 *)(dwt->wavelet + 1 - dwt->cas);
    a += dwt->sn;
    x0 = dwt->win_h_x0;
    x1 = dwt->win_h_x1;
}
}
