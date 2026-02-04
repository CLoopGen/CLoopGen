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
    OPJ_FLOAT32 *restrict src = a;
    OPJ_FLOAT32 *restrict dest_block = bi;
    if (remaining_height >= 8 && ((OPJ_SIZE_T)a & 15) == 0 && ((OPJ_SIZE_T)bi & 15) == 0) {
        // Change memory access pattern to consecutive write layout using transposed indexing
        for (i = x0; i < x1; ++i) {
            OPJ_FLOAT32 temp[8];
            // Load vertically strided elements into a temporary array (transpose step)
            for (OPJ_UINT32 row = 0; row < 8; ++row) {
                temp[row] = src[i + row * width];
            }
            // Store consecutively in output (coalesced store)
            OPJ_FLOAT32 *restrict dst = dest_block + i * 2 * 8;
            for (OPJ_UINT32 m = 0; m < 8; ++m) {
                dst[m] = temp[m];
            }
        }
    } else {
        for (i = x0; i < x1; ++i) {
            OPJ_FLOAT32 *restrict dst = dest_block + i * 2 * 8;
            // Unroll with direct conditional checks per level, but use pointer arithmetic directly
            OPJ_FLOAT32 *ptr = &src[i];
            dst[0] = *ptr;
            if (remaining_height == 1) continue;
            ptr += width;
            dst[1] = *ptr;
            if (remaining_height == 2) continue;
            ptr += width;
            dst[2] = *ptr;
            if (remaining_height == 3) continue;
            ptr += width;
            dst[3] = *ptr;
            if (remaining_height == 4) continue;
            ptr += width;
            dst[4] = *ptr;
            if (remaining_height == 5) continue;
            ptr += width;
            dst[5] = *ptr;
            if (remaining_height == 6) continue;
            ptr += width;
            dst[6] = *ptr;
            if (remaining_height == 7) continue;
            ptr += width;
            dst[7] = *ptr;
        }
    }
    bi = (OPJ_FLOAT32 *)(dwt->wavelet + 1 - dwt->cas);
    a += dwt->sn;
    x0 = dwt->win_h_x0;
    x1 = dwt->win_h_x1;
}
}
