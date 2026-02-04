#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG tmp14;
extern JLONG tmp15;
extern JLONG tmp16;
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG tmp25;
extern JLONG tmp26;
extern JLONG tmp27;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant with reduced loop-carried dependencies and reordered computation
for (ctr = 0; ctr < 15; ++ctr) {
    outptr = output_buf[ctr] + output_col;

    // Load all wsptr values upfront to minimize memory dependency chains
    JLONG w0 = wsptr[0], w1 = wsptr[1], w2 = wsptr[2], w3 = wsptr[3];
    JLONG w4 = wsptr[4], w5 = wsptr[5], w6 = wsptr[6], w7 = wsptr[7];

    // Eliminate loop-carried dependency on z1 by making it purely local
    JLONG t1 = (w0 + (1 << 2)) << 13;
    JLONG t2 = w6 * (JLONG)(0.437016024 * (1 << 13) + 0.5);
    JLONG t3 = w6 * (JLONG)(1.1441228059999999 * (1 << 13) + 0.5);

    JLONG stage1_tmp12 = t1 - t2;
    JLONG stage1_tmp13 = t1 + t3;
    JLONG stage1_z1 = t1 - ((t3 - t2) << 1);

    JLONG sum_w2_w4 = w2 + w4;
    JLONG dif_w2_w4 = w2 - w4;

    JLONG c1 = (JLONG)(1.33762899 * (1 << 13) + 0.5);
    JLONG c2 = (JLONG)(0.045680613000000002 * (1 << 13) + 0.5);
    JLONG c3 = (JLONG)(1.4397739460000001 * (1 << 13) + 0.5);

    JLONG partA = sum_w2_w4 * c1;
    JLONG partB = dif_w2_w4 * c2;
    JLONG scaled_w2 = w2 * c3;

    JLONG tmp20 = stage1_tmp13 + partA + partB;
    JLONG tmp23 = stage1_tmp12 - partA + partB + scaled_w2;

    // Use fused multiply-add patterns where possible
    JLONG base_val = (JLONG)(0.54705957400000005 * (1 << 13) + 0.5);
    JLONG tmp_val = sum_w2_w4 * base_val;
    JLONG adj = dif_w2_w4 * (JLONG)(0.39923400399999998 * (1 << 13) + 0.5);
    JLONG tmp25 = stage1_tmp13 - tmp_val - adj;
    JLONG tmp26 = stage1_tmp12 + tmp_val - adj - scaled_w2;

    base_val = (JLONG)(0.790569415 * (1 << 13) + 0.5);
    adj = dif_w2_w4 * (JLONG)(0.35355339099999999 * (1 << 13) + 0.5);
    tmp_val = sum_w2_w4 * base_val;
    JLONG tmp21 = stage1_tmp12 + tmp_val + adj;
    JLONG tmp24 = stage1_tmp13 - tmp_val + adj;
    adj += adj;
    JLONG tmp22 = stage1_z1 + adj;
    JLONG tmp27 = stage1_z1 - adj - adj;

    // Second half computations now independent of first half via full privatization
    JLONG z1_second = w1;
    JLONG z2_second = w3;
    JLONG z4_second = w5;
    JLONG z3_second = z4_second * (JLONG)(1.224744871 * (1 << 13) + 0.5);
    JLONG z4_final = w7;
    JLONG diff_z2_z4 = z2_second - z4_final;
    JLONG sum_z1_diff = z1_second + diff_z2_z4;
    JLONG factor = (JLONG)(0.831253876 * (1 << 13) + 0.5);
    JLONG tmp15_second = sum_z1_diff * factor;
    JLONG tmp11_second = tmp15_second + (z1_second * (JLONG)(0.51374314799999998 * (1 << 13) + 0.5));
    JLONG tmp14_second = tmp15_second - (diff_z2_z4 * (JLONG)(2.1762508989999998 * (1 << 13) + 0.5));
    JLONG neg_factor1 = -(factor);
    JLONG neg_factor2 = -(JLONG)(1.344997024 * (1 << 13) + 0.5);
    JLONG tmp13_second = z2_second * neg_factor1;
    JLONG tmp15_second_2 = z2_second * neg_factor2;

    JLONG diff_z1_z4f = z1_second - z4_final;
    JLONG tmp12_second = z3_second + (diff_z1_z4f * (JLONG)(1.4064663529999999 * (1 << 13) + 0.5));
    JLONG tmp10_second = tmp12_second + (z4_final * (JLONG)(2.4574318439999998 * (1 << 13) + 0.5)) - tmp15_second_2;
    JLONG tmp16_second = tmp12_second - (z1_second * (JLONG)(1.11243482 * (1 << 13) + 0.5)) + tmp13_second;
    JLONG tmp12_second_2 = (diff_z1_z4f * (JLONG)(1.224744871 * (1 << 13) + 0.5)) - z3_second;
    JLONG sum_z1_z4f = z1_second + z4_final;
    JLONG z2_recomputed = sum_z1_z4f * (JLONG)(0.575212477 * (1 << 13) + 0.5);
    tmp13_second += z2_recomputed + (z1_second * (JLONG)(0.47575301399999997 * (1 << 13) + 0.5)) - z3_second;
    tmp15_second_2 += z2_recomputed - (z4_final * (JLONG)(0.86924400999999996 * (1 << 13) + 0.5)) + z3_second;

    // Final stores remain unchanged but use computed temporaries
    int shift_amt = 17; // 13 + 1 + 3
    int limit_mask = 1023; // 255*4+3
    outptr[0]  = range_limit[(int)((tmp20 + tmp10_second) >> shift_amt) & limit_mask];
    outptr[14] = range_limit[(int)((tmp20 - tmp10_second) >> shift_amt) & limit_mask];
    outptr[1]  = range_limit[(int)((tmp21 + adj) >> shift_amt) & limit_mask];
    outptr[13] = range_limit[(int)((tmp21 - adj) >> shift_amt) & limit_mask];
    outptr[2]  = range_limit[(int)((tmp22 + tmp12_second_2) >> shift_amt) & limit_mask];
    outptr[12] = range_limit[(int)((tmp22 - tmp12_second_2) >> shift_amt) & limit_mask];
    outptr[3]  = range_limit[(int)((tmp23 + tmp13_second) >> shift_amt) & limit_mask];
    outptr[11] = range_limit[(int)((tmp23 - tmp13_second) >> shift_amt) & limit_mask];
    outptr[4]  = range_limit[(int)((tmp24 + tmp14_second) >> shift_amt) & limit_mask];
    outptr[10] = range_limit[(int)((tmp24 - tmp14_second) >> shift_amt) & limit_mask];
    outptr[5]  = range_limit[(int)((tmp25 + tmp15_second_2) >> shift_amt) & limit_mask];
    outptr[9]  = range_limit[(int)((tmp25 - tmp15_second_2) >> shift_amt) & limit_mask];
    outptr[6]  = range_limit[(int)((tmp26 + tmp16_second) >> shift_amt) & limit_mask];
    outptr[8]  = range_limit[(int)((tmp26 - tmp16_second) >> shift_amt) & limit_mask];
    outptr[7]  = range_limit[(int)(tmp27 >> shift_amt) & limit_mask];

    wsptr += 8;
}
}
