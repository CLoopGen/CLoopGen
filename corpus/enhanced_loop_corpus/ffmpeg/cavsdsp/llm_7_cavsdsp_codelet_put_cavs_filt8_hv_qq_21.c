#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    // Reduce data reuse by precomputing shared terms and reordering accesses
    // Eliminate some loop-carried dependencies by making operations more independent

    const int tidx = i; // Break potential address aliasing assumptions
    const int offset = tidx * 1; // Localize index calculation

    // Reorder and coalesce memory loads to reduce RAW hazards through early fetch
    const int tmp_vals[] = {
        tmp[-2 * 8], tmp[-1 * 8], tmp[0 * 8], tmp[1 * 8], tmp[2 * 8],
        tmp[3 * 8], tmp[4 * 8], tmp[5 * 8], tmp[6 * 8], tmp[7 * 8],
        tmp[8 * 8], tmp[9 * 8], tmp[10 * 8]
    };

    #define tmpB tmp_vals[0]
    #define tmpA tmp_vals[1]
    #define tmp0 tmp_vals[2]
    #define tmp1 tmp_vals[3]
    #define tmp2 tmp_vals[4]
    #define tmp3 tmp_vals[5]
    #define tmp4 tmp_vals[6]
    #define tmp5 tmp_vals[7]
    #define tmp6 tmp_vals[8]
    #define tmp7 tmp_vals[9]
    #define tmp8 tmp_vals[10]
    #define tmp9 tmp_vals[11]
    #define tmp10 tmp_vals[12]

    // Unroll and fuse computation to increase instruction-level parallelism
    uint8_t results[8];
    results[0] = cm[((0 * tmpB + -7 * tmpA + 42 * tmp0 + 96 * tmp1 + -2 * tmp2 + -1 * tmp3) + 512) >> 10];
    results[1] = cm[((0 * tmpA + -7 * tmp0 + 42 * tmp1 + 96 * tmp2 + -2 * tmp3 + -1 * tmp4) + 512) >> 10];
    results[2] = cm[((0 * tmp0 + -7 * tmp1 + 42 * tmp2 + 96 * tmp3 + -2 * tmp4 + -1 * tmp5) + 512) >> 10];
    results[3] = cm[((0 * tmp1 + -7 * tmp2 + 42 * tmp3 + 96 * tmp4 + -2 * tmp5 + -1 * tmp6) + 512) >> 10];
    results[4] = cm[((0 * tmp2 + -7 * tmp3 + 42 * tmp4 + 96 * tmp5 + -2 * tmp6 + -1 * tmp7) + 512) >> 10];
    results[5] = cm[((0 * tmp3 + -7 * tmp4 + 42 * tmp5 + 96 * tmp6 + -2 * tmp7 + -1 * tmp8) + 512) >> 10];
    results[6] = cm[((0 * tmp4 + -7 * tmp5 + 42 * tmp6 + 96 * tmp7 + -2 * tmp8 + -1 * tmp9) + 512) >> 10];
    results[7] = cm[((0 * tmp5 + -7 * tmp6 + 42 * tmp7 + 96 * tmp8 + -2 * tmp9 + -1 * tmp10) + 512) >> 10];

    // Store all results in batch to reduce interleaving of load/store (reduces WAR/WAW)
    dst[0 * dstStride] = results[0];
    dst[1 * dstStride] = results[1];
    dst[2 * dstStride] = results[2];
    dst[3 * dstStride] = results[3];
    dst[4 * dstStride] = results[4];
    dst[5 * dstStride] = results[5];
    dst[6 * dstStride] = results[6];
    dst[7 * dstStride] = results[7];

    // Advance pointers without dependency on computed values (remove artificial carry)
    dst++;
    tmp++;
}
}
