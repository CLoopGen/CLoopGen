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
for (ctr = 0; ctr < 14; ctr++) {
    outptr = output_buf[ctr] + output_col;

    // Combine initial computations into fewer intermediate values to increase loop-carried dependency depth
    JLONG w0 = (JLONG)wsptr[0], w1 = (JLONG)wsptr[1], w2 = (JLONG)wsptr[2], w3 = (JLONG)wsptr[3];
    JLONG w4 = (JLONG)wsptr[4], w5 = (JLONG)wsptr[5], w6 = (JLONG)wsptr[6], w7 = (JLONG)wsptr[7];

    // Fold multiple operations into composite expressions to create stronger intra-loop dependencies
    JLONG base_shift = (JLONG)1 << 13;
    JLONG s1 = ((w0 + ((JLONG)1 << 2)) << 13);
    JLONG s4 = w4 * (((JLONG)((0.88174773399999995) * base_shift + 0.5)));
    JLONG s2 = w4 * (((JLONG)((1.274162392) * base_shift + 0.5)));
    JLONG s3 = w4 * (((JLONG)((0.31469212299999999) * base_shift + 0.5)));

    // Create cumulative dependency chain: each temp depends on prior result
    JLONG chain1 = s1 + s2;
    JLONG chain2 = s1 + s3;
    JLONG chain3 = s1 - s4;
    JLONG chain4 = s1 - (((unsigned long)(s2 + s3 - s4)) << 1);

    JLONG sum26 = w2 + w6;
    JLONG scale_factor_a = (JLONG)((1.105676686) * base_shift + 0.5);
    JLONG scale_factor_b = (JLONG)((0.27307958999999998) * base_shift + 0.5);
    JLONG scale_factor_c = (JLONG)((1.719280954) * base_shift + 0.5);
    JLONG scale_factor_d = (JLONG)((0.61360426800000001) * base_shift + 0.5);
    JLONG scale_factor_e = (JLONG)((1.3787562760000001) * base_shift + 0.5);

    JLONG part_a = sum26 * scale_factor_a;
    JLONG part_b = w2 * scale_factor_b;
    JLONG part_c = w6 * scale_factor_c;
    JLONG part_d = (w2 * scale_factor_d) - (w6 * scale_factor_e);

    JLONG chain5 = chain1 + (part_a + part_b);
    JLONG chain6 = chain1 - (part_a + part_b);
    JLONG chain7 = chain2 + (part_a - part_c);
    JLONG chain8 = chain2 - (part_a - part_c);
    JLONG chain9 = chain3 + part_d;
    JLONG chain10 = chain3 - part_d;

    // Introduce artificial loop-carried dependency via reuse of prior iteration's value
    static JLONG prev_z1 = 0; // Carry state across iterations
    JLONG current_input_sum = w1 + w3 + w5 + w7 + prev_z1; // Depends on previous iteration
    prev_z1 = (current_input_sum >> 13); // Update for next

    // Reorder and fuse remaining calculations with deeper dependency tree
    JLONG u1 = w1 + w3;
    JLONG u2 = w1 + w2;
    JLONG u3 = w3 + w5;
    JLONG u4 = w5 - w3;

    JLONG f1 = (JLONG)((1.334852607) * base_shift + 0.5);
    JLONG f2 = (JLONG)((1.1974488459999999) * base_shift + 0.5);
    JLONG f3 = (JLONG)((1.1269801690000001) * base_shift + 0.5);
    JLONG f4 = (JLONG)((0.752406978) * base_shift + 0.5);
    JLONG f5 = (JLONG)((1.061150426) * base_shift + 0.5);
    JLONG f6 = (JLONG)((0.46708512899999999) * base_shift + 0.5);
    JLONG f7 = (JLONG)((-0.15834168100000001) * base_shift + 0.5);
    JLONG f8 = (JLONG)((0.42410394800000001) * base_shift + 0.5);
    JLONG f9 = (JLONG)((2.3739597730000002) * base_shift + 0.5);
    JLONG f10 = (JLONG)((1.405321284) * base_shift + 0.5);
    JLONG f11 = (JLONG)((1.6906431334000001) * base_shift + 0.5);
    JLONG f12 = (JLONG)((0.67495756699999998) * base_shift + 0.5);

    JLONG v1 = u2 * f1;
    JLONG v2 = u1 * f2;
    JLONG v3 = u1 * f4;
    JLONG v4 = u3 * f7;
    JLONG v5 = (w1 - w2) * f6;

    JLONG shifted_w7 = ((JLONG)((unsigned long)(w7) << (13)));

    JLONG final_chain_1 = v1 + v2 + shifted_w7 - (w1 * f3);
    JLONG final_chain_2 = v3 - (w1 * f5) + v5 - shifted_w7;
    JLONG final_chain_3 = v1 + v4 - (w2 * f8) - shifted_w7;
    JLONG final_chain_4 = v2 + v4 - (w5 * f9) - shifted_w7;
    JLONG final_chain_5 = u4 * f10;
    JLONG final_chain_6 = v3 + final_chain_5 + shifted_w7 - (w5 * f11);
    JLONG final_chain_7 = v5 + final_chain_5 + (w2 * f12);
    JLONG final_chain_8 = ((JLONG)((unsigned long)((w1 - w2) - w5) << 13)) + shifted_w7;

    // Write outputs in sequential index order to maintain correctness
    outptr[0] = range_limit[(int)((chain5 + final_chain_1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[1] = range_limit[(int)((chain7 + final_chain_3) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[2] = range_limit[(int)((chain9 + final_chain_4) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[3] = range_limit[(int)((chain4 + final_chain_8) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[4] = range_limit[(int)((chain10 + final_chain_6) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[5] = range_limit[(int)((chain8 + final_chain_2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[6] = range_limit[(int)((chain6 + final_chain_7) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[7] = range_limit[(int)((chain6 - final_chain_7) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[8] = range_limit[(int)((chain8 - final_chain_2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[9] = range_limit[(int)((chain10 - final_chain_6) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[10] = range_limit[(int)((chain4 - final_chain_8) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[11] = range_limit[(int)((chain9 - final_chain_4) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[12] = range_limit[(int)((chain7 - final_chain_3) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[13] = range_limit[(int)((chain5 - final_chain_1) >> (13 + 1 + 3)) & (255 * 4 + 3)];

    wsptr += 8;
}
}
