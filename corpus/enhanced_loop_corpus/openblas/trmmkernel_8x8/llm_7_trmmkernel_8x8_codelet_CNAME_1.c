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
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res1_4;
extern float res1_5;
extern float res1_6;
extern float res1_7;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn & 2); j += 2) {
    C0 = C;
    C1 = C0 + ldc;
    ptrba = ba;
    for (i = 0; i < bm / 8; i += 1) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 = 0;
        res1_0 = res1_1 = res1_2 = res1_3 = res1_4 = res1_5 = res1_6 = res1_7 = 0;
        temp = off + 2;
        k = 0;
        while (k < temp) {  // Introducing conditional dependency via early exit simulation using break
            b0 = ptrbb[0]; b1 = ptrbb[1];
            a0 = ptrba[0]; a1 = ptrba[1];
            float prod_a0_b0 = a0 * b0;
            float prod_a0_b1 = a0 * b1;
            float prod_a1_b0 = a1 * b0;
            float prod_a1_b1 = a1 * b1;

            res0_0 += prod_a0_b0; res1_0 += prod_a0_b1;
            res0_1 += prod_a1_b0; res1_1 += prod_a1_b1;

            a0 = ptrba[2]; a1 = ptrba[3];
            prod_a0_b0 = a0 * b0; prod_a0_b1 = a0 * b1;
            prod_a1_b0 = a1 * b0; prod_a1_b1 = a1 * b1;
            res0_2 += prod_a0_b0; res1_2 += prod_a0_b1;
            res0_3 += prod_a1_b0; res1_3 += prod_a1_b1;

            a0 = ptrba[4]; a1 = ptrba[5];
            prod_a0_b0 = a0 * b0; prod_a0_b1 = a0 * b1;
            prod_a1_b0 = a1 * b0; prod_a1_b1 = a1 * b1;
            res0_4 += prod_a0_b0; res1_4 += prod_a0_b1;
            res0_5 += prod_a1_b0; res1_5 += prod_a1_b1;

            a0 = ptrba[6]; a1 = ptrba[7];
            prod_a0_b0 = a0 * b0; prod_a0_b1 = a0 * b1;
            prod_a1_b0 = a1 * b0; prod_a1_b1 = a1 * b1;
            res0_6 += prod_a0_b0; res1_6 += prod_a0_b1;
            res0_7 += prod_a1_b0; res1_7 += prod_a1_b1;

            ptrba += 8;
            ptrbb += 2;
            k++;
            if (k > bk) break;  // Artificial WAW/RAR dependency introduced: k used in computation and condition
        }
        float scale = alpha;
        res0_0 *= scale; res0_1 *= scale; res0_2 *= scale; res0_3 *= scale;
        res0_4 *= scale; res0_5 *= scale; res0_6 *= scale; res0_7 *= scale;
        res1_0 *= scale; res1_1 *= scale; res1_2 *= scale; res1_3 *= scale;
        res1_4 *= scale; res1_5 *= scale; res1_6 *= scale; res1_7 *= scale;

        C0[0]=res0_0; C0[1]=res0_1; C0[2]=res0_2; C0[3]=res0_3;
        C0[4]=res0_4; C0[5]=res0_5; C0[6]=res0_6; C0[7]=res0_7;
        C1[0]=res1_0; C1[1]=res1_1; C1[2]=res1_2; C1[3]=res1_3;
        C1[4]=res1_4; C1[5]=res1_5; C1[6]=res1_6; C1[7]=res1_7;

        temp = (bk - off - 2);
        ptrba += temp * 8;
        ptrbb += temp * 2;
        C0 += 8; C1 += 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = 0;
        res1_0 = res1_1 = res1_2 = res1_3 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1];
            a0 = ptrba[0]; a1 = ptrba[1];
            float t0 = a0 * b0, t1 = a0 * b1;
            float t2 = a1 * b0, t3 = a1 * b1;
            res0_0 += t0; res1_0 += t1;
            res0_1 += t2; res1_1 += t3;

            a0 = ptrba[2]; a1 = ptrba[3];
            t0 = a0 * b0; t1 = a0 * b1;
            t2 = a1 * b0; t3 = a1 * b1;
            res0_2 += t0; res1_2 += t1;
            res0_3 += t2; res1_3 += t3;

            ptrba += 4;
            ptrbb += 2;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        res1_0 *= alpha; res1_1 *= alpha; res1_2 *= alpha; res1_3 *= alpha;
        C0[0]=res0_0; C0[1]=res0_1; C0[2]=res0_2; C0[3]=res0_3;
        C1[0]=res1_0; C1[1]=res1_1; C1[2]=res1_2; C1[3]=res1_3;

        temp = bk - off - 2;
        ptrba += temp * 4;
        ptrbb += temp * 2;
        C0 += 4; C1 += 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = res0_1 = 0;
        res1_0 = res1_1 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1];
            a0 = ptrba[0]; a1 = ptrba[1];
            float p0 = a0 * b0, p1 = a0 * b1;
            float p2 = a1 * b0, p3 = a1 * b1;
            res0_0 += p0; res1_0 += p1;
            res0_1 += p2; res1_1 += p3;
            ptrba += 2;
            ptrbb += 2;
        }
        res0_0 *= alpha; res0_1 *= alpha;
        res1_0 *= alpha; res1_1 *= alpha;
        C0[0] = res0_0; C0[1] = res0_1;
        C1[0] = res1_0; C1[1] = res1_1;

        temp = bk - off - 2;
        ptrba += temp * 2;
        ptrbb += temp * 2;
        C0 += 2; C1 += 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = res1_0 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1];
            a0 = ptrba[0];
            float tmp_prod0 = a0 * b0;
            float tmp_prod1 = a0 * b1;
            res0_0 += tmp_prod0;
            res1_0 += tmp_prod1;
            ptrba++;
            ptrbb += 2;
        }
        res0_0 *= alpha; res1_0 *= alpha;
        C0[0] = res0_0; C1[0] = res1_0;

        temp = bk - off - 2;
        ptrba += temp;
        ptrbb += temp * 2;
        C0++; C1++;
    }
    k = bk << 1;
    bb = bb + k;
    C = C + (ldc << 1);
}
}
