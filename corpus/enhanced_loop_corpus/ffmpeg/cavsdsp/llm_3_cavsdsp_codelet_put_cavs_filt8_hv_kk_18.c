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
    const int idx_base = i;
    const int16_t *tmp_vec = &tmp[idx_base];
    const uint8_t *cm_base = cm;

    // Consecutive load simulation via vector-like indexing with fixed offset array
    const int offsets[] = {-16, -8, 0, 8, 16, 24, 32, 40, 48, 56, 64, 72}; // scaled by 8 for byte alignment
    const int tmp_vals[12] = {
        tmp_vec[offsets[0]], tmp_vec[offsets[1]], tmp_vec[offsets[2]], tmp_vec[offsets[3]],
        tmp_vec[offsets[4]], tmp_vec[offsets[5]], tmp_vec[offsets[6]], tmp_vec[offsets[7]],
        tmp_vec[offsets[8]], tmp_vec[offsets[9]], tmp_vec[offsets[10]], tmp_vec[offsets[11]]
    };

    #define TMP(n) tmp_vals[n+2]  // shift base so that TMP(0) refers to tmp[0*8]
    #define DST(i) dst[(i) * dstStride]

    DST(0) = cm_base[((0 * TMP(-2) + -1 * TMP(-1) + 5 * TMP(0) + 5 * TMP(1) + -1 * TMP(2) + 0 * TMP(3)) + 512) >> 10];
    DST(1) = cm_base[((0 * TMP(-1) + -1 * TMP(0) + 5 * TMP(1) + 5 * TMP(2) + -1 * TMP(3) + 0 * TMP(4)) + 512) >> 10];
    DST(2) = cm_base[((0 * TMP(0) + -1 * TMP(1) + 5 * TMP(2) + 5 * TMP(3) + -1 * TMP(4) + 0 * TMP(5)) + 512) >> 10];
    DST(3) = cm_base[((0 * TMP(1) + -1 * TMP(2) + 5 * TMP(3) + 5 * TMP(4) + -1 * TMP(5) + 0 * TMP(6)) + 512) >> 10];
    DST(4) = cm_base[((0 * TMP(2) + -1 * TMP(3) + 5 * TMP(4) + 5 * TMP(5) + -1 * TMP(6) + 0 * TMP(7)) + 512) >> 10];
    DST(5) = cm_base[((0 * TMP(3) + -1 * TMP(4) + 5 * TMP(5) + 5 * TMP(6) + -1 * TMP(7) + 0 * TMP(8)) + 512) >> 10];
    DST(6) = cm_base[((0 * TMP(4) + -1 * TMP(5) + 5 * TMP(6) + 5 * TMP(7) + -1 * TMP(8) + 0 * TMP(9)) + 512) >> 10];
    DST(7) = cm_base[((0 * TMP(5) + -1 * TMP(6) + 5 * TMP(7) + 5 * TMP(8) + -1 * TMP(9) + 0 * TMP(10)) + 512) >> 10];

    #undef TMP
    #undef DST

    dst++;
    tmp++;
}
}
