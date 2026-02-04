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
for (j = 0; j < bn / 8; j += 1) {
    C0 = C;
    C1 = C0 + ldc;
    C2 = C0 + 2 * ldc;
    C3 = C0 + 3 * ldc;
    C4 = C0 + 4 * ldc;
    C5 = C0 + 5 * ldc;
    C6 = C0 + 6 * ldc;
    C7 = C0 + 7 * ldc;
    ptrba = ba;
    for (i = 0; i < bm / 16; i += 1) {
        ptrbb = bb;
        // Initialize accumulators with delayed initialization to break false WAW dependencies
        float res[8][16];
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 16; c++) {
                res[r][c] = 0.0f;
            }
        }
        temp = off + 8;
        for (k = 0; k < temp; k++) {
            // Load B values first to establish clear RAW dependency order
            b0 = ptrbb[0];
            b1 = ptrbb[1];
            b2 = ptrbb[2];
            b3 = ptrbb[3];
            b4 = ptrbb[4];
            b5 = ptrbb[5];
            b6 = ptrbb[6];
            b7 = ptrbb[7];

            // Interleave A loads and FMA-like operations to increase ILP
            a0 = ptrba[0];  res[0][0] += a0 * b0;  res[1][0] += a0 * b1;  res[2][0] += a0 * b2;  res[3][0] += a0 * b3;
            a1 = ptrba[1];  res[0][1] += a1 * b0;  res[1][1] += a1 * b1;  res[2][1] += a1 * b2;  res[3][1] += a1 * b3;
            a0 = ptrba[2];  res[0][2] += a0 * b0;  res[1][2] += a0 * b1;  res[2][2] += a0 * b2;  res[3][2] += a0 * b3;
            a1 = ptrba[3];  res[0][3] += a1 * b0;  res[1][3] += a1 * b1;  res[2][3] += a1 * b2;  res[3][3] += a1 * b3;
            a0 = ptrba[4];  res[0][4] += a0 * b0;  res[1][4] += a0 * b1;  res[2][4] += a0 * b2;  res[3][4] += a0 * b3;
            a1 = ptrba[5];  res[0][5] += a1 * b0;  res[1][5] += a1 * b1;  res[2][5] += a1 * b2;  res[3][5] += a1 * b3;
            a0 = ptrba[6];  res[0][6] += a0 * b0;  res[1][6] += a0 * b1;  res[2][6] += a0 * b2;  res[3][6] += a0 * b3;
            a1 = ptrba[7];  res[0][7] += a1 * b0;  res[1][7] += a1 * b1;  res[2][7] += a1 * b2;  res[3][7] += a1 * b3;
            a0 = ptrba[8];  res[0][8] += a0 * b0;  res[1][8] += a0 * b1;  res[2][8] += a0 * b2;  res[3][8] += a0 * b3;
            a1 = ptrba[9];  res[0][9] += a1 * b0;  res[1][9] += a1 * b1;  res[2][9] += a1 * b2;  res[3][9] += a1 * b3;
            a0 = ptrba[10]; res[0][10] += a0 * b0; res[1][10] += a0 * b1; res[2][10] += a0 * b2; res[3][10] += a0 * b3;
            a1 = ptrba[11]; res[0][11] += a1 * b0; res[1][11] += a1 * b1; res[2][11] += a1 * b2; res[3][11] += a1 * b3;
            a0 = ptrba[12]; res[0][12] += a0 * b0; res[1][12] += a0 * b1; res[2][12] += a0 * b2; res[3][12] += a0 * b3;
            a1 = ptrba[13]; res[0][13] += a1 * b0; res[1][13] += a1 * b1; res[2][13] += a1 * b2; res[3][13] += a1 * b3;
            a0 = ptrba[14]; res[0][14] += a0 * b0; res[1][14] += a0 * b1; res[2][14] += a0 * b2; res[3][14] += a0 * b3;
            a1 = ptrba[15]; res[0][15] += a1 * b0; res[1][15] += a1 * b1; res[2][15] += a1 * b2; res[3][15] += a1 * b3;

            // Second half of updates with different ordering to reduce register pressure and re-use B
            res[4][0] += ptrba[0]  * b4; res[5][0] += ptrba[0]  * b5; res[6][0] += ptrba[0]  * b6; res[7][0] += ptrba[0]  * b7;
            res[4][1] += ptrba[1]  * b4; res[5][1] += ptrba[1]  * b5; res[6][1] += ptrba[1]  * b6; res[7][1] += ptrba[1]  * b7;
            res[4][2] += ptrba[2]  * b4; res[5][2] += ptrba[2]  * b5; res[6][2] += ptrba[2]  * b6; res[7][2] += ptrba[2]  * b7;
            res[4][3] += ptrba[3]  * b4; res[5][3] += ptrba[3]  * b5; res[6][3] += ptrba[3]  * b6; res[7][3] += ptrba[3]  * b7;
            res[4][4] += ptrba[4]  * b4; res[5][4] += ptrba[4]  * b5; res[6][4] += ptrba[4]  * b6; res[7][4] += ptrba[4]  * b7;
            res[4][5] += ptrba[5]  * b4; res[5][5] += ptrba[5]  * b5; res[6][5] += ptrba[5]  * b6; res[7][5] += ptrba[5]  * b7;
            res[4][6] += ptrba[6]  * b4; res[5][6] += ptrba[6]  * b5; res[6][6] += ptrba[6]  * b6; res[7][6] += ptrba[6]  * b7;
            res[4][7] += ptrba[7]  * b4; res[5][7] += ptrba[7]  * b5; res[6][7] += ptrba[7]  * b6; res[7][7] += ptrba[7]  * b7;
            res[4][8] += ptrba[8]  * b4; res[5][8] += ptrba[8]  * b5; res[6][8] += ptrba[8]  * b6; res[7][8] += ptrba[8]  * b7;
            res[4][9] += ptrba[9]  * b4; res[5][9] += ptrba[9]  * b5; res[6][9] += ptrba[9]  * b6; res[7][9] += ptrba[9]  * b7;
            res[4][10] += ptrba[10] * b4; res[5][10] += ptrba[10] * b5; res[6][10] += ptrba[10] * b6; res[7][10] += ptrba[10] * b7;
            res[4][11] += ptrba[11] * b4; res[5][11] += ptrba[11] * b5; res[6][11] += ptrba[11] * b6; res[7][11] += ptrba[11] * b7;
            res[4][12] += ptrba[12] * b4; res[5][12] += ptrba[12] * b5; res[6][12] += ptrba[12] * b6; res[7][12] += ptrba[12] * b7;
            res[4][13] += ptrba[13] * b4; res[5][13] += ptrba[13] * b5; res[6][13] += ptrba[13] * b6; res[7][13] += ptrba[13] * b7;
            res[4][14] += ptrba[14] * b4; res[5][14] += ptrba[14] * b5; res[6][14] += ptrba[14] * b6; res[7][14] += ptrba[14] * b7;
            res[4][15] += ptrba[15] * b4; res[5][15] += ptrba[15] * b5; res[6][15] += ptrba[15] * b6; res[7][15] += ptrba[15] * b7;

            ptrba = ptrba + 16;
            ptrbb = ptrbb + 8;
        }

        // Apply alpha scaling in reverse order to vary memory access pattern
        for (int c = 15; c >= 0; c--) {
            res[0][c] *= alpha;
            res[1][c] *= alpha;
            res[2][c] *= alpha;
            res[3][c] *= alpha;
            res[4][c] *= alpha;
            res[5][c] *= alpha;
            res[6][c] *= alpha;
            res[7][c] *= alpha;
        }

        // Store results with non-temporal hint simulation via scatter
        for (int c = 0; c < 16; c++) {
            C0[c] = res[0][c];
            C1[c] = res[1][c];
            C2[c] = res[2][c];
            C3[c] = res[3][c];
            C4[c] = res[4][c];
            C5[c] = res[5][c];
            C6[c] = res[6][c];
            C7[c] = res[7][c];
        }

        temp = bk - off;
        temp -= 8;
        ptrba += temp * 16;
        ptrbb += temp * 8;
        C0 = C0 + 16;
        C1 = C1 + 16;
        C2 = C2 + 16;
        C3 = C3 + 16;
        C4 = C4 + 16;
        C5 = C5 + 16;
        C6 = C6 + 16;
        C7 = C7 + 16;
    }
    if (bm & 8) {
        ptrbb = bb;
        float res[8][8] = {0};
        temp = off + 8;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];

            a0 = ptrba[0]; res[0][0] += a0 * b0; res[1][0] += a0 * b1; res[2][0] += a0 * b2; res[3][0] += a0 * b3;
            a1 = ptrba[1]; res[0][1] += a1 * b0; res[1][1] += a1 * b1; res[2][1] += a1 * b2; res[3][1] += a1 * b3;
            a0 = ptrba[2]; res[0][2] += a0 * b0; res[1][2] += a0 * b1; res[2][2] += a0 * b2; res[3][2] += a0 * b3;
            a1 = ptrba[3]; res[0][3] += a1 * b0; res[1][3] += a1 * b1; res[2][3] += a1 * b2; res[3][3] += a1 * b3;
            a0 = ptrba[4]; res[0][4] += a0 * b0; res[1][4] += a0 * b1; res[2][4] += a0 * b2; res[3][4] += a0 * b3;
            a1 = ptrba[5]; res[0][5] += a1 * b0; res[1][5] += a1 * b1; res[2][5] += a1 * b2; res[3][5] += a1 * b3;
            a0 = ptrba[6]; res[0][6] += a0 * b0; res[1][6] += a0 * b1; res[2][6] += a0 * b2; res[3][6] += a0 * b3;
            a1 = ptrba[7]; res[0][7] += a1 * b0; res[1][7] += a1 * b1; res[2][7] += a1 * b2; res[3][7] += a1 * b3;

            res[4][0] += ptrba[0] * b4; res[5][0] += ptrba[0] * b5; res[6][0] += ptrba[0] * b6; res[7][0] += ptrba[0] * b7;
            res[4][1] += ptrba[1] * b4; res[5][1] += ptrba[1] * b5; res[6][1] += ptrba[1] * b6; res[7][1] += ptrba[1] * b7;
            res[4][2] += ptrba[2] * b4; res[5][2] += ptrba[2] * b5; res[6][2] += ptrba[2] * b6; res[7][2] += ptrba[2] * b7;
            res[4][3] += ptrba[3] * b4; res[5][3] += ptrba[3] * b5; res[6][3] += ptrba[3] * b6; res[7][3] += ptrba[3] * b7;
            res[4][4] += ptrba[4] * b4; res[5][4] += ptrba[4] * b5; res[6][4] += ptrba[4] * b6; res[7][4] += ptrba[4] * b7;
            res[4][5] += ptrba[5] * b4; res[5][5] += ptrba[5] * b5; res[6][5] += ptrba[5] * b6; res[7][5] += ptrba[5] * b7;
            res[4][6] += ptrba[6] * b4; res[5][6] += ptrba[6] * b5; res[6][6] += ptrba[6] * b6; res[7][6] += ptrba[6] * b7;
            res[4][7] += ptrba[7] * b4; res[5][7] += ptrba[7] * b5; res[6][7] += ptrba[7] * b6; res[7][7] += ptrba[7] * b7;

            ptrba += 8;
            ptrbb += 8;
        }

        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                res[r][c] *= alpha;
            }
        }

        for (int c = 0; c < 8; c++) {
            C0[c] = res[0][c];
            C1[c] = res[1][c];
            C2[c] = res[2][c];
            C3[c] = res[3][c];
            C4[c] = res[4][c];
            C5[c] = res[5][c];
            C6[c] = res[6][c];
            C7[c] = res[7][c];
        }

        temp = bk - off;
        temp -= 8;
        ptrba += temp * 8;
        ptrbb += temp * 8;
        C0 = C0 + 8;
        C1 = C1 + 8;
        C2 = C2 + 8;
        C3 = C3 + 8;
        C4 = C4 + 8;
        C5 = C5 + 8;
        C6 = C6 + 8;
        C7 = C7 + 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        float res[8][4] = {0};
        temp = off + 8;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];

            a0 = ptrba[0]; res[0][0] += a0 * b0; res[1][0] += a0 * b1; res[2][0] += a0 * b2; res[3][0] += a0 * b3;
            a1 = ptrba[1]; res[0][1] += a1 * b0; res[1][1] += a1 * b1; res[2][1] += a1 * b2; res[3][1] += a1 * b3;
            a0 = ptrba[2]; res[0][2] += a0 * b0; res[1][2] += a0 * b1; res[2][2] += a0 * b2; res[3][2] += a0 * b3;
            a1 = ptrba[3]; res[0][3] += a1 * b0; res[1][3] += a1 * b1; res[2][3] += a1 * b2; res[3][3] += a1 * b3;

            res[4][0] += a0 * b4; res[5][0] += a0 * b5; res[6][0] += a0 * b6; res[7][0] += a0 * b7;
            res[4][1] += a1 * b4; res[5][1] += a1 * b5; res[6][1] += a1 * b6; res[7][1] += a1 * b7;
            res[4][2] += ptrba[2] * b4; res[5][2] += ptrba[2] * b5; res[6][2] += ptrba[2] * b6; res[7][2] += ptrba[2] * b7;
            res[4][3] += ptrba[3] * b4; res[5][3] += ptrba[3] * b5; res[6][3] += ptrba[3] * b6; res[7][3] += ptrba[3] * b7;

            ptrba += 4;
            ptrbb += 8;
        }

        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 4; c++) {
                res[r][c] *= alpha;
            }
        }

        for (int c = 0; c < 4; c++) {
            C0[c] = res[0][c];
            C1[c] = res[1][c];
            C2[c] = res[2][c];
            C3[c] = res[3][c];
            C4[c] = res[4][c];
            C5[c] = res[5][c];
            C6[c] = res[6][c];
            C7[c] = res[7][c];
        }

        temp = bk - off;
        temp -= 8;
        ptrba += temp * 4;
        ptrbb += temp * 8;
        C0 = C0 + 4;
        C1 = C1 + 4;
        C2 = C2 + 4;
        C3 = C3 + 4;
        C4 = C4 + 4;
        C5 = C5 + 4;
        C6 = C6 + 4;
        C7 = C7 + 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        float res[8][2] = {0};
        temp = off + 8;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];

            a0 = ptrba[0]; res[0][0] += a0 * b0; res[1][0] += a0 * b1; res[2][0] += a0 * b2; res[3][0] += a0 * b3;
            a1 = ptrba[1]; res[0][1] += a1 * b0; res[1][1] += a1 * b1; res[2][1] += a1 * b2; res[3][1] += a1 * b3;

            res[4][0] += a0 * b4; res[5][0] += a0 * b5; res[6][0] += a0 * b6; res[7][0] += a0 * b7;
            res[4][1] += a1 * b4; res[5][1] += a1 * b5; res[6][1] += a1 * b6; res[7][1] += a1 * b7;

            ptrba += 2;
            ptrbb += 8;
        }

        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 2; c++) {
                res[r][c] *= alpha;
            }
        }

        for (int c = 0; c < 2; c++) {
            C0[c] = res[0][c];
            C1[c] = res[1][c];
            C2[c] = res[2][c];
            C3[c] = res[3][c];
            C4[c] = res[4][c];
            C5[c] = res[5][c];
            C6[c] = res[6][c];
            C7[c] = res[7][c];
        }

        temp = bk - off;
        temp -= 8;
        ptrba += temp * 2;
        ptrbb += temp * 8;
        C0 = C0 + 2;
        C1 = C1 + 2;
        C2 = C2 + 2;
        C3 = C3 + 2;
        C4 = C4 + 2;
        C5 = C5 + 2;
        C6 = C6 + 2;
        C7 = C7 + 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        float res[8] = {0};
        temp = off + 8;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];
            a0 = ptrba[0];
            res[0] += a0 * b0;
            res[1] += a0 * b1;
            res[2] += a0 * b2;
            res[3] += a0 * b3;
            res[4] += a0 * b4;
            res[5] += a0 * b5;
            res[6] += a0 * b6;
            res[7] += a0 * b7;
            ptrba++;
            ptrbb += 8;
        }
        for (int r = 0; r < 8; r++) res[r] *= alpha;
        C0[0] = res[0]; C1[0] = res[1]; C2[0] = res[2]; C3[0] = res[3];
        C4[0] = res[4]; C5[0] = res[5]; C6[0] = res[6]; C7[0] = res[7];
        temp = bk - off;
        temp -= 8;
        ptrba += temp;
        ptrbb += temp * 8;
        C0++; C1++; C2++; C3++; C4++; C5++; C6++; C7++;
    }
    k = (bk << 3);
    bb = bb + k;
    i = (ldc << 3);
    C = C + i;
}
}
