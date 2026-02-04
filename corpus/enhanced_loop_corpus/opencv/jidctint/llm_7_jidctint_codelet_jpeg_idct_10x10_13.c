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
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
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
for (ctr = 0; ctr < 10; ctr++) {
    outptr = output_buf[ctr] + output_col;
    
    // Eliminate some temporary variables to remove WAW and WAR hazards
    // Fuse computations directly into final expressions where possible
    // Also break loop-carried dependencies by using local temporaries

    JLONG local_z3 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
    local_z3 = ((JLONG)((unsigned long)(local_z3) << (13)));
    JLONG local_z4 = (JLONG)wsptr[4];
    JLONG local_z1 = ((local_z4) * (((JLONG)((1.1441228059999999) * (((JLONG)1) << 13) + 0.5))));
    JLONG local_z2 = ((local_z4) * (((JLONG)((0.437016024) * (((JLONG)1) << 13) + 0.5))));

    JLONG tmp10 = local_z3 + local_z1;
    JLONG tmp11 = local_z3 - local_z2;
    JLONG tmp22 = local_z3 - ((JLONG)((unsigned long)(local_z1 - local_z2) << (1)));

    JLONG w2 = (JLONG)wsptr[2], w6 = (JLONG)wsptr[6];
    JLONG sum26 = w2 + w6;
    JLONG coeff_a = (((JLONG)((0.831253876) * (((JLONG)1) << 13) + 0.5)));
    JLONG coeff_b = (((JLONG)((0.51374314799999998) * (((JLONG)1) << 13) + 0.5)));
    JLONG coeff_c = (((JLONG)((2.1762508989999998) * (((JLONG)1) << 13) + 0.5)));
    JLONG tmp12 = (sum26 * coeff_a) + (w2 * coeff_b);
    JLONG tmp13 = (sum26 * coeff_a) - (w6 * coeff_c);

    JLONG tmp20 = tmp10 + tmp12;
    JLONG tmp24 = tmp10 - tmp12;
    JLONG tmp21 = tmp11 + tmp13;
    JLONG tmp23 = tmp11 - tmp13;

    JLONG w1 = (JLONG)wsptr[1], w3 = (JLONG)wsptr[3], w5 = (JLONG)wsptr[5], w7 = (JLONG)wsptr[7];
    JLONG w5s = ((JLONG)((unsigned long)(w5) << (13)));
    JLONG sum37 = w3 + w7, diff37 = w3 - w7;
    JLONG scaled_diff37 = diff37 * (((JLONG)((0.30901699399999999) * (((JLONG)1) << 13) + 0.5)));
    JLONG term95 = sum37 * (((JLONG)((0.95105651599999996) * (((JLONG)1) << 13) + 0.5)));
    JLONG term58 = sum37 * (((JLONG)((0.58778525199999998) * (((JLONG)1) << 13) + 0.5)));
    JLONG z4_part = w5s + scaled_diff37;
    JLONG tmp10_val = w1 * (((JLONG)((1.3968022470000001) * (((JLONG)1) << 13) + 0.5))) + term95 + z4_part;
    JLONG tmp14_val = w1 * (((JLONG)((0.22123174200000001) * (((JLONG)1) << 13) + 0.5))) - term95 + z4_part;
    JLONG z4_part2 = w5s - scaled_diff37 - ((JLONG)((unsigned long)(diff37) << (12)));
    JLONG tmp12_val = ((JLONG)((unsigned long)(w1 - diff37) << (13))) - w5s;
    JLONG tmp11_val = w1 * (((JLONG)((1.2600735110000001) * (((JLONG)1) << 13) + 0.5))) - term58 - z4_part2;
    JLONG tmp13_val = w1 * (((JLONG)((0.64203952200000003) * (((JLONG)1) << 13) + 0.5))) - term58 + z4_part2;

    // Write outputs with direct indexing, no overlapping temp reuse (reduced WAW)
    outptr[0] = range_limit[(int)((tmp20 + tmp10_val) >> 17) & 1023];
    outptr[9] = range_limit[(int)((tmp20 - tmp10_val) >> 17) & 1023];
    outptr[1] = range_limit[(int)((tmp21 + tmp11_val) >> 17) & 1023];
    outptr[8] = range_limit[(int)((tmp21 - tmp11_val) >> 17) & 1023];
    outptr[2] = range_limit[(int)((tmp22 + tmp12_val) >> 17) & 1023];
    outptr[7] = range_limit[(int)((tmp22 - tmp12_val) >> 17) & 1023];
    outptr[3] = range_limit[(int)((tmp23 + tmp13_val) >> 17) & 1023];
    outptr[6] = range_limit[(int)((tmp23 - tmp13_val) >> 17) & 1023];
    outptr[4] = range_limit[(int)((tmp24 + tmp14_val) >> 17) & 1023];
    outptr[5] = range_limit[(int)((tmp24 - tmp14_val) >> 17) & 1023];

    wsptr += 8;
}
}
