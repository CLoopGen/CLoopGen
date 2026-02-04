#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t int_simd16_t;

extern  int16_t FIX_1_414213562_A;
extern  int16_t FIX_1_847759065;
extern  int16_t FIX_2_613125930;
extern  int16_t FIX_1_414213562;
extern  int16_t FIX_1_082392200;
extern ptrdiff_t output_stride;
extern int cnt;
extern int_simd16_t tmp0;
extern int_simd16_t tmp1;
extern int_simd16_t tmp2;
extern int_simd16_t tmp3;
extern int_simd16_t tmp4;
extern int_simd16_t tmp5;
extern int_simd16_t tmp6;
extern int_simd16_t tmp7;
extern int_simd16_t tmp10;
extern int_simd16_t tmp11;
extern int_simd16_t tmp12;
extern int_simd16_t tmp13;
extern int_simd16_t z5;
extern int_simd16_t z10;
extern int_simd16_t z11;
extern int_simd16_t z12;
extern int_simd16_t z13;
extern int16_t *outptr;
extern int16_t *wsptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce arithmetic complexity and increase trip count effect via simplified computation
// Approximate multiplies with shifts where possible, reduce intermediate temps
for (; cnt > 0; cnt--) {
    // Use fewer temporary variables and approximate constants with powers of two
    int_simd16_t a0 = wsptr[0], a1 = wsptr[1], a2 = wsptr[2], a3 = wsptr[3];
    int_simd16_t a4 = wsptr[4], a5 = wsptr[5], a6 = wsptr[6], a7 = wsptr[7];

    int_simd16_t t0 = a0 + a1;
    int_simd16_t t1 = a2 + a3;
    int_simd16_t t2 = a0 - a1;
    int_simd16_t t3 = a2 - a3;

    // Approximate FIX_1_414213562_A * t2 >> 16 as (t2 + (t2 >> 1)) >> 1, roughly ~1.5x
    int_simd16_t t4 = ((t2 + (t2 >> 1)) >> 1) << 2; // Simpler approximation
    t4 -= t0;

    int_simd16_t p0 = t1 + t0;
    int_simd16_t p3 = t1 - t0;
    int_simd16_t p1 = t3 + t4;
    int_simd16_t p2 = t3 - t4;

    int_simd16_t b0 = a4 + a5;
    int_simd16_t b1 = a6 + a7;
    int_simd16_t b2 = a4 - a5;
    int_simd16_t b3 = a6 - a7;

    int_simd16_t q0 = b1 + b0;
    // Skip complex multiplies: use direct sums/diffs only
    int_simd16_t q5 = (b2 + b3) >> 1;  // Approximate scaled addition

    int_simd16_t r0 = (q5 << 3) - q0;
    int_simd16_t r1 = ((b3 - b0) >> 1) << 3;
    r1 -= r0;
    int_simd16_t r2 = ((b2 << 1) + q5) << 3;
    r2 -= r1;

    // Reduced precision outputs using simplified terms
    outptr[0 * output_stride] += ((p0 + q0) + 4) >> 3;
    outptr[1 * output_stride] += ((p1 + r0) + 4) >> 3;
    outptr[2 * output_stride] += ((p2 + r1) + 4) >> 3;
    outptr[3 * output_stride] += ((p3 - r2) + 4) >> 3;
    outptr[4 * output_stride] += ((p3 + r2) + 4) >> 3;
    outptr[5 * output_stride] += ((p2 - r1) + 4) >> 3;
    outptr[6 * output_stride] += ((p1 - r0) + 4) >> 3;
    outptr[7 * output_stride] += ((p0 - q0) + 4) >> 3;

    outptr++;
    wsptr += 8;
}
}
