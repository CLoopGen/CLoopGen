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
    opj_v8_t *restrict wavelet_ptr = dwt->wavelet;
    OPJ_INT32 sn_val = dwt->sn;
    OPJ_UINT32 win_h_x0_val = dwt->win_h_x0;
    OPJ_UINT32 win_h_x1_val = dwt->win_h_x1;
    OPJ_INT32 cas_val = dwt->cas;
    if (remaining_height >= 8 && ((OPJ_SIZE_T)a & 15) == 0 && ((OPJ_SIZE_T)bi & 15) == 0) {
        for (i = x0; i < x1; ++i) {
            OPJ_UINT32 base_idx = i;
            OPJ_FLOAT32 val0 = a[base_idx];
            OPJ_FLOAT32 val1 = a[base_idx + width];
            OPJ_FLOAT32 val2 = a[base_idx + 2*width];
            OPJ_FLOAT32 val3 = a[base_idx + 3*width];
            OPJ_FLOAT32 val4 = a[base_idx + 4*width];
            OPJ_FLOAT32 val5 = a[base_idx + 5*width];
            OPJ_FLOAT32 val6 = a[base_idx + 6*width];
            OPJ_FLOAT32 val7 = a[base_idx + 7*width];
            OPJ_FLOAT32 *restrict dst = bi + i * 2 * 8;
            dst[7] = val7;
            dst[6] = val6;
            dst[5] = val5;
            dst[4] = val4;
            dst[3] = val3;
            dst[2] = val2;
            dst[1] = val1;
            dst[0] = val0;
        }
    } else {
        for (i = x0; i < x1; ++i) {
            OPJ_UINT32 j = i;
            OPJ_FLOAT32 *restrict dst = bi + i * 2 * 8;
            dst[0] = a[j];
            j += width;
            if (remaining_height > 1) {
                dst[1] = a[j];
                j += width;
                if (remaining_height > 2) {
                    dst[2] = a[j];
                    j += width;
                    if (remaining_height > 3) {
                        dst[3] = a[j];
                        j += width;
                        if (remaining_height > 4) {
                            dst[4] = a[j];
                            j += width;
                            if (remaining_height > 5) {
                                dst[5] = a[j];
                                j += width;
                                if (remaining_height > 6) {
                                    dst[6] = a[j];
                                    j += width;
                                    if (remaining_height > 7) {
                                        dst[7] = a[j];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    bi = (OPJ_FLOAT32 *)(wavelet_ptr + 1 - cas_val);
    a += sn_val;
    x0 = win_h_x0_val;
    x1 = win_h_x1_val;
}
}
