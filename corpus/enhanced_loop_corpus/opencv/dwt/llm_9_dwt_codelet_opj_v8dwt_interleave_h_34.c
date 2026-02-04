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
for (k = 0; k < 1; ++k) {
    if (remaining_height >= 8 && ((OPJ_SIZE_T)a & 15) == 0 && ((OPJ_SIZE_T)bi & 15) == 0) {
        i = x0;
        while (i + 3 < x1) {
            OPJ_UINT32 j0 = i;
            OPJ_UINT32 j1 = i+1;
            OPJ_UINT32 j2 = i+2;
            OPJ_UINT32 j3 = i+3;
            OPJ_FLOAT32 *restrict dst0 = bi + i * 2 * 8;
            OPJ_FLOAT32 *restrict dst1 = dst0 + 2*8;
            OPJ_FLOAT32 *restrict dst2 = dst1 + 2*8;
            OPJ_FLOAT32 *restrict dst3 = dst2 + 2*8;

            dst0[0] = a[j0]; dst1[0] = a[j1]; dst2[0] = a[j2]; dst3[0] = a[j3];
            j0 += width; j1 += width; j2 += width; j3 += width;
            dst0[1] = a[j0]; dst1[1] = a[j1]; dst2[1] = a[j2]; dst3[1] = a[j3];
            j0 += width; j1 += width; j2 += width; j3 += width;
            dst0[2] = a[j0]; dst1[2] = a[j1]; dst2[2] = a[j2]; dst3[2] = a[j3];
            j0 += width; j1 += width; j2 += width; j3 += width;
            dst0[3] = a[j0]; dst1[3] = a[j1]; dst2[3] = a[j2]; dst3[3] = a[j3];
            j0 += width; j1 += width; j2 += width; j3 += width;
            dst0[4] = a[j0]; dst1[4] = a[j1]; dst2[4] = a[j2]; dst3[4] = a[j3];
            j0 += width; j1 += width; j2 += width; j3 += width;
            dst0[5] = a[j0]; dst1[5] = a[j1]; dst2[5] = a[j2]; dst3[5] = a[j3];
            j0 += width; j1 += width; j2 += width; j3 += width;
            dst0[6] = a[j0]; dst1[6] = a[j1]; dst2[6] = a[j2]; dst3[6] = a[j3];
            j0 += width; j1 += width; j2 += width; j3 += width;
            dst0[7] = a[j0]; dst1[7] = a[j1]; dst2[7] = a[j2]; dst3[7] = a[j3];

            i += 4;
        }
        for (; i < x1; ++i) {
            OPJ_UINT32 j = i;
            OPJ_FLOAT32 *restrict dst = bi + i * 2 * 8;
            dst[0] = a[j];
            j += width;
            if (remaining_height <= 1) continue;
            dst[1] = a[j];
            j += width;
            if (remaining_height <= 2) continue;
            dst[2] = a[j];
            j += width;
            if (remaining_height <= 3) continue;
            dst[3] = a[j];
            j += width;
            if (remaining_height <= 4) continue;
            dst[4] = a[j];
            j += width;
            if (remaining_height <= 5) continue;
            dst[5] = a[j];
            j += width;
            if (remaining_height <= 6) continue;
            dst[6] = a[j];
            j += width;
            if (remaining_height <= 7) continue;
            dst[7] = a[j];
        }
    } else {
        for (i = x0; i < x1; ++i) {
            OPJ_UINT32 j = i;
            OPJ_FLOAT32 *restrict dst = bi + i * 2 * 8;
            dst[0] = a[j];
            j += width;
            if (remaining_height == 1) continue;
            dst[1] = a[j];
            j += width;
            if (remaining_height == 2) continue;
            dst[2] = a[j];
            j += width;
            if (remaining_height == 3) continue;
            dst[3] = a[j];
            j += width;
            if (remaining_height == 4) continue;
            dst[4] = a[j];
            j += width;
            if (remaining_height == 5) continue;
            dst[5] = a[j];
            j += width;
            if (remaining_height == 6) continue;
            dst[6] = a[j];
            j += width;
            if (remaining_height == 7) continue;
            dst[7] = a[j];
        }
    }
    bi = (OPJ_FLOAT32 *)(dwt->wavelet + 1 - dwt->cas);
    a += dwt->sn;
    x0 = dwt->win_h_x0;
    x1 = dwt->win_h_x1;
}
}
