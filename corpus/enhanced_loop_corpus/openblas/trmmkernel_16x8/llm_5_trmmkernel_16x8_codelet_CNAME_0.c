#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG bm;
extern BLASLONG bn;
extern BLASLONG bk;
extern float alpha;
extern float *ba;
extern float *bb;
extern float *C;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG k;
extern float *C0;
extern float *C1;
extern float *C2;
extern float *C3;
extern float *C4;
extern float *C5;
extern float *C6;
extern float *C7;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res0_2;
extern float res0_3;
extern float res0_4;
extern float res0_5;
extern float res0_6;
extern float res0_7;
extern float res0_8;
extern float res0_9;
extern float res0_10;
extern float res0_11;
extern float res0_12;
extern float res0_13;
extern float res0_14;
extern float res0_15;
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res1_4;
extern float res1_5;
extern float res1_6;
extern float res1_7;
extern float res1_8;
extern float res1_9;
extern float res1_10;
extern float res1_11;
extern float res1_12;
extern float res1_13;
extern float res1_14;
extern float res1_15;
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res2_4;
extern float res2_5;
extern float res2_6;
extern float res2_7;
extern float res2_8;
extern float res2_9;
extern float res2_10;
extern float res2_11;
extern float res2_12;
extern float res2_13;
extern float res2_14;
extern float res2_15;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float res3_4;
extern float res3_5;
extern float res3_6;
extern float res3_7;
extern float res3_8;
extern float res3_9;
extern float res3_10;
extern float res3_11;
extern float res3_12;
extern float res3_13;
extern float res3_14;
extern float res3_15;
extern float res4_0;
extern float res4_1;
extern float res4_2;
extern float res4_3;
extern float res4_4;
extern float res4_5;
extern float res4_6;
extern float res4_7;
extern float res4_8;
extern float res4_9;
extern float res4_10;
extern float res4_11;
extern float res4_12;
extern float res4_13;
extern float res4_14;
extern float res4_15;
extern float res5_0;
extern float res5_1;
extern float res5_2;
extern float res5_3;
extern float res5_4;
extern float res5_5;
extern float res5_6;
extern float res5_7;
extern float res5_8;
extern float res5_9;
extern float res5_10;
extern float res5_11;
extern float res5_12;
extern float res5_13;
extern float res5_14;
extern float res5_15;
extern float res6_0;
extern float res6_1;
extern float res6_2;
extern float res6_3;
extern float res6_4;
extern float res6_5;
extern float res6_6;
extern float res6_7;
extern float res6_8;
extern float res6_9;
extern float res6_10;
extern float res6_11;
extern float res6_12;
extern float res6_13;
extern float res6_14;
extern float res6_15;
extern float res7_0;
extern float res7_1;
extern float res7_2;
extern float res7_3;
extern float res7_4;
extern float res7_5;
extern float res7_6;
extern float res7_7;
extern float res7_8;
extern float res7_9;
extern float res7_10;
extern float res7_11;
extern float res7_12;
extern float res7_13;
extern float res7_14;
extern float res7_15;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern float b4;
extern float b5;
extern float b6;
extern float b7;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < bn / 8; ++j) {
    C0 = C;
    C1 = C0 + ldc;
    C2 = C0 + 2 * ldc;
    C3 = C0 + 3 * ldc;
    C4 = C0 + 4 * ldc;
    C5 = C0 + 5 * ldc;
    C6 = C0 + 6 * ldc;
    C7 = C0 + 7 * ldc;
    ptrba = ba;
    i = 0;
    while (i < bm / 16) {
        ptrbb = bb;
        #define INIT_REG(r) \
            res##r##_0=res##r##_1=res##r##_2=res##r##_3=res##r##_4=res##r##_5=res##r##_6=res##r##_7=\
            res##r##_8=res##r##_9=res##r##_10=res##r##_11=res##r##_12=res##r##_13=res##r##_14=res##r##_15=0

        INIT_REG(0); INIT_REG(1); INIT_REG(2); INIT_REG(3);
        INIT_REG(4); INIT_REG(5); INIT_REG(6); INIT_REG(7);

        temp = off + 8;
        for (k = 0; k < temp; ++k) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];

            #define MAC(acc, a_idx, b_idx) acc += ptrba[a_idx] * b##b_idx

            MAC(res0_0, 0, 0); MAC(res1_0, 0, 1); MAC(res2_0, 0, 2); MAC(res3_0, 0, 3);
            MAC(res4_0, 0, 4); MAC(res5_0, 0, 5); MAC(res6_0, 0, 6); MAC(res7_0, 0, 7);

            MAC(res0_1, 1, 0); MAC(res1_1, 1, 1); MAC(res2_1, 1, 2); MAC(res3_1, 1, 3);
            MAC(res4_1, 1, 4); MAC(res5_1, 1, 5); MAC(res6_1, 1, 6); MAC(res7_1, 1, 7);

            MAC(res0_2, 2, 0); MAC(res1_2, 2, 1); MAC(res2_2, 2, 2); MAC(res3_2, 2, 3);
            MAC(res4_2, 2, 4); MAC(res5_2, 2, 5); MAC(res6_2, 2, 6); MAC(res7_2, 2, 7);

            MAC(res0_3, 3, 0); MAC(res1_3, 3, 1); MAC(res2_3, 3, 2); MAC(res3_3, 3, 3);
            MAC(res4_3, 3, 4); MAC(res5_3, 3, 5); MAC(res6_3, 3, 6); MAC(res7_3, 3, 7);

            MAC(res0_4, 4, 0); MAC(res1_4, 4, 1); MAC(res2_4, 4, 2); MAC(res3_4, 4, 3);
            MAC(res4_4, 4, 4); MAC(res5_4, 4, 5); MAC(res6_4, 4, 6); MAC(res7_4, 4, 7);

            MAC(res0_5, 5, 0); MAC(res1_5, 5, 1); MAC(res2_5, 5, 2); MAC(res3_5, 5, 3);
            MAC(res4_5, 5, 4); MAC(res5_5, 5, 5); MAC(res6_5, 5, 6); MAC(res7_5, 5, 7);

            MAC(res0_6, 6, 0); MAC(res1_6, 6, 1); MAC(res2_6, 6, 2); MAC(res3_6, 6, 3);
            MAC(res4_6, 6, 4); MAC(res5_6, 6, 5); MAC(res6_6, 6, 6); MAC(res7_6, 6, 7);

            MAC(res0_7, 7, 0); MAC(res1_7, 7, 1); MAC(res2_7, 7, 2); MAC(res3_7, 7, 3);
            MAC(res4_7, 7, 4); MAC(res5_7, 7, 5); MAC(res6_7, 7, 6); MAC(res7_7, 7, 7);

            MAC(res0_8, 8, 0); MAC(res1_8, 8, 1); MAC(res2_8, 8, 2); MAC(res3_8, 8, 3);
            MAC(res4_8, 8, 4); MAC(res5_8, 8, 5); MAC(res6_8, 8, 6); MAC(res7_8, 8, 7);

            MAC(res0_9, 9, 0); MAC(res1_9, 9, 1); MAC(res2_9, 9, 2); MAC(res3_9, 9, 3);
            MAC(res4_9, 9, 4); MAC(res5_9, 9, 5); MAC(res6_9, 9, 6); MAC(res7_9, 9, 7);

            MAC(res0_10,10,0); MAC(res1_10,10,1); MAC(res2_10,10,2); MAC(res3_10,10,3);
            MAC(res4_10,10,4); MAC(res5_10,10,5); MAC(res6_10,10,6); MAC(res7_10,10,7);

            MAC(res0_11,11,0); MAC(res1_11,11,1); MAC(res2_11,11,2); MAC(res3_11,11,3);
            MAC(res4_11,11,4); MAC(res5_11,11,5); MAC(res6_11,11,6); MAC(res7_11,11,7);

            MAC(res0_12,12,0); MAC(res1_12,12,1); MAC(res2_12,12,2); MAC(res3_12,12,3);
            MAC(res4_12,12,4); MAC(res5_12,12,5); MAC(res6_12,12,6); MAC(res7_12,12,7);

            MAC(res0_13,13,0); MAC(res1_13,13,1); MAC(res2_13,13,2); MAC(res3_13,13,3);
            MAC(res4_13,13,4); MAC(res5_13,13,5); MAC(res6_13,13,6); MAC(res7_13,13,7);

            MAC(res0_14,14,0); MAC(res1_14,14,1); MAC(res2_14,14,2); MAC(res3_14,14,3);
            MAC(res4_14,14,4); MAC(res5_14,14,5); MAC(res6_14,14,6); MAC(res7_14,14,7);

            MAC(res0_15,15,0); MAC(res1_15,15,1); MAC(res2_15,15,2); MAC(res3_15,15,3);
            MAC(res4_15,15,4); MAC(res5_15,15,5); MAC(res6_15,15,6); MAC(res7_15,15,7);

            ptrba += 16;
            ptrbb += 8;
        }

        #define SCALE_STORE(reg, Ci, idx) \
            Ci[idx] = reg * alpha

        #define STORE_ROW(r) \
            SCALE_STORE(res##r##_0, C##r, 0); SCALE_STORE(res##r##_1, C##r, 1); \
            SCALE_STORE(res##r##_2, C##r, 2); SCALE_STORE(res##r##_3, C##r, 3); \
            SCALE_STORE(res##r##_4, C##r, 4); SCALE_STORE(res##r##_5, C##r, 5); \
            SCALE_STORE(res##r##_6, C##r, 6); SCALE_STORE(res##r##_7, C##r, 7); \
            SCALE_STORE(res##r##_8, C##r, 8); SCALE_STORE(res##r##_9, C##r, 9); \
            SCALE_STORE(res##r##_10,C##r,10); SCALE_STORE(res##r##_11,C##r,11); \
            SCALE_STORE(res##r##_12,C##r,12); SCALE_STORE(res##r##_13,C##r,13); \
            SCALE_STORE(res##r##_14,C##r,14); SCALE_STORE(res##r##_15,C##r,15)

        STORE_ROW(0); STORE_ROW(1); STORE_ROW(2); STORE_ROW(3);
        STORE_ROW(4); STORE_ROW(5); STORE_ROW(6); STORE_ROW(7);

        temp = bk - off - 8;
        ptrba += temp * 16;
        ptrbb += temp * 8;
        C0 += 16; C1 += 16; C2 += 16; C3 += 16;
        C4 += 16; C5 += 16; C6 += 16; C7 += 16;
        ++i;
    }

    temp = bm & 15;
    if (temp >= 8) {
        goto process_8;
    } else if (temp >= 4) {
        goto process_4;
    } else if (temp >= 2) {
        goto process_2;
    } else if (temp == 1) {
        goto process_1;
    } else {
        goto skip_remainder;
    }

process_16:
    // Placeholder to avoid label fall-through issues
    goto end_remainder;

process_8:
    ptrbb = bb;
    #undef INIT_REG
    #define INIT_REG(r) \
        res##r##_0=res##r##_1=res##r##_2=res##r##_3=res##r##_4=res##r##_5=res##r##_6=res##r##_7=0

    INIT_REG(0); INIT_REG(1); INIT_REG(2); INIT_REG(3);
    INIT_REG(4); INIT_REG(5); INIT_REG(6); INIT_REG(7);

    temp = off + 8;
    for (k = 0; k < temp; ++k) {
        b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
        b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];

        a0 = ptrba[0]; a1 = ptrba[1]; a0 = ptrba[2]; a1 = ptrba[3];
        a0 = ptrba[4]; a1 = ptrba[5]; a0 = ptrba[6]; a1 = ptrba[7];

        res0_0 += a0*b0; res1_0 += a0*b1; res2_0 += a0*b2; res3_0 += a0*b3;
        res4_0 += a0*b4; res5_0 += a0*b5; res6_0 += a0*b6; res7_0 += a0*b7;

        res0_1 += a1*b0; res1_1 += a1*b1; res2_1 += a1*b2; res3_1 += a1*b3;
        res4_1 += a1*b4; res5_1 += a1*b5; res6_1 += a1*b6; res7_1 += a1*b7;

        ptrba += 8;
        ptrbb += 8;
    }

    #undef SCALE_STORE
    #define SCALE_STORE(reg, Ci, idx) Ci[idx] = reg * alpha

    #undef STORE_ROW
    #define STORE_ROW(r) \
        SCALE_STORE(res##r##_0, C##r, 0); SCALE_STORE(res##r##_1, C##r, 1); \
        SCALE_STORE(res##r##_2, C##r, 2); SCALE_STORE(res##r##_3, C##r, 3); \
        SCALE_STORE(res##r##_4, C##r, 4); SCALE_STORE(res##r##_5, C##r, 5); \
        SCALE_STORE(res##r##_6, C##r, 6); SCALE_STORE(res##r##_7, C##r, 7)

    STORE_ROW(0); STORE_ROW(1); STORE_ROW(2); STORE_ROW(3);
    STORE_ROW(4); STORE_ROW(5); STORE_ROW(6); STORE_ROW(7);

    temp = bk - off - 8;
    ptrba += temp * 8;
    ptrbb += temp * 8;
    C0 += 8; C1 += 8; C2 += 8; C3 += 8;
    C4 += 8; C5 += 8; C6 += 8; C7 += 8;

    temp = bm & 7;
    if (temp >= 4) goto process_4;
    else if (temp >= 2) goto process_2;
    else if (temp == 1) goto process_1;
    else goto skip_remainder;

process_4:
    ptrbb = bb;
    INIT_REG(0); INIT_REG(1); INIT_REG(2); INIT_REG(3);
    INIT_REG(4); INIT_REG(5); INIT_REG(6); INIT_REG(7);

    temp = off + 8;
    for (k = 0; k < temp; ++k) {
        b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
        b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];

        a0 = ptrba[0]; a1 = ptrba[1];
        res0_0 += a0*b0; res1_0 += a0*b1; res2_0 += a0*b2; res3_0 += a0*b3;
        res4_0 += a0*b4; res5_0 += a0*b5; res6_0 += a0*b6; res7_0 += a0*b7;
        res0_1 += a1*b0; res1_1 += a1*b1; res2_1 += a1*b2; res3_1 += a1*b3;
        res4_1 += a1*b4; res5_1 += a1*b5; res6_1 += a1*b6; res7_1 += a1*b7;

        a0 = ptrba[2]; a1 = ptrba[3];
        res0_2 += a0*b0; res1_2 += a0*b1; res2_2 += a0*b2; res3_2 += a0*b3;
        res4_2 += a0*b4; res5_2 += a0*b5; res6_2 += a0*b6; res7_2 += a0*b7;
        res0_3 += a1*b0; res1_3 += a1*b1; res2_3 += a1*b2; res3_3 += a1*b3;
        res4_3 += a1*b4; res5_3 += a1*b5; res6_3 += a1*b6; res7_3 += a1*b7;

        ptrba += 4;
        ptrbb += 8;
    }

    #undef STORE_ROW
    #define STORE_ROW(r) \
        SCALE_STORE(res##r##_0, C##r, 0); SCALE_STORE(res##r##_1, C##r, 1); \
        SCALE_STORE(res##r##_2, C##r, 2); SCALE_STORE(res##r##_3, C##r, 3)

    STORE_ROW(0); STORE_ROW(1); STORE_ROW(2); STORE_ROW(3);
    STORE_ROW(4); STORE_ROW(5); STORE_ROW(6); STORE_ROW(7);

    temp = bk - off - 8;
    ptrba += temp * 4;
    ptrbb += temp * 8;
    C0 += 4; C1 += 4; C2 += 4; C3 += 4;
    C4 += 4; C5 += 4; C6 += 4; C7 += 4;

    temp = bm & 3;
    if (temp >= 2) goto process_2;
    else if (temp == 1) goto process_1;
    else goto skip_remainder;

process_2:
    ptrbb = bb;
    res0_0 = res0_1 = res1_0 = res1_1 = res2_0 = res2_1 = res3_0 = res3_1 =
    res4_0 = res4_1 = res5_0 = res5_1 = res6_0 = res6_1 = res7_0 = res7_1 = 0;

    temp = off + 8;
    for (k = 0; k < temp; ++k) {
        b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
        b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];

        a0 = ptrba[0];
        res0_0 += a0*b0; res1_0 += a0*b1; res2_0 += a0*b2; res3_0 += a0*b3;
        res4_0 += a0*b4; res5_0 += a0*b5; res6_0 += a0*b6; res7_0 += a0*b7;

        a1 = ptrba[1];
        res0_1 += a1*b0; res1_1 += a1*b1; res2_1 += a1*b2; res3_1 += a1*b3;
        res4_1 += a1*b4; res5_1 += a1*b5; res6_1 += a1*b6; res7_1 += a1*b7;

        ptrba += 2;
        ptrbb += 8;
    }

    #undef STORE_ROW
    #define STORE_ROW(r) \
        SCALE_STORE(res##r##_0, C##r, 0); SCALE_STORE(res##r##_1, C##r, 1)

    STORE_ROW(0); STORE_ROW(1); STORE_ROW(2); STORE_ROW(3);
    STORE_ROW(4); STORE_ROW(5); STORE_ROW(6); STORE_ROW(7);

    temp = bk - off - 8;
    ptrba += temp * 2;
    ptrbb += temp * 8;
    C0 += 2; C1 += 2; C2 += 2; C3 += 2;
    C4 += 2; C5 += 2; C6 += 2; C7 += 2;

    if (bm & 1) goto process_1;
    else goto skip_remainder;

process_1:
    ptrbb = bb;
    res0_0 = res1_0 = res2_0 = res3_0 = res4_0 = res5_0 = res6_0 = res7_0 = 0;

    temp = off + 8;
    for (k = 0; k < temp; ++k) {
        b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
        b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];

        a0 = ptrba[0];
        res0_0 += a0*b0; res1_0 += a0*b1; res2_0 += a0*b2; res3_0 += a0*b3;
        res4_0 += a0*b4; res5_0 += a0*b5; res6_0 += a0*b6; res7_0 += a0*b7;

        ptrba += 1;
        ptrbb += 8;
    }

    #undef STORE_ROW
    #define STORE_ROW(r) SCALE_STORE(res##r##_0, C##r, 0)
    STORE_ROW(0); STORE_ROW(1); STORE_ROW(2); STORE_ROW(3);
    STORE_ROW(4); STORE_ROW(5); STORE_ROW(6); STORE_ROW(7);

    temp = bk - off - 8;
    ptrba += temp;
    ptrbb += temp * 8;
    C0 += 1; C1 += 1; C2 += 1; C3 += 1;
    C4 += 1; C5 += 1; C6 += 1; C7 += 1;

skip_remainder:
end_remainder:

    k = bk * 8;
    bb += k;
    C += ldc * 8;
}
}
