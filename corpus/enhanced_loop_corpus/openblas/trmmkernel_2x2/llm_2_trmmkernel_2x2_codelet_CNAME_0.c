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
extern float res0;
extern float res1;
extern float res2;
extern float res3;
extern float load0;
extern float load1;
extern float load2;
extern float load3;
extern float load4;
extern float load5;
extern float load6;
extern float load7;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < bn / 2; j += 1) {
    C0 = C;
    C1 = C0 + ldc;
    ptrba = ba + (off << 1); // Pre-offset pointer to reduce arithmetic in inner loop
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        res2 = 0;
        res3 = 0;
        temp = off + 2;
        // Unroll by 2 instead of 4 for reduced register pressure and more predictable memory strides
        for (k = 0; k < temp / 2; k += 1) {
            // First block: consecutive access with unit stride
            load0 = ptrba[0]; load1 = ptrbb[0];
            res0 += load0 * load1;
            load2 = ptrba[1]; 
            res1 += load2 * load1;
            load3 = ptrbb[1];
            res2 += load0 * load3;
            res3 += load2 * load3;

            // Second block from same segment
            load4 = ptrba[2]; load5 = ptrbb[2];
            res0 += load4 * load5;
            load6 = ptrba[3];
            res1 += load6 * load5;
            load7 = ptrbb[3];
            res2 += load4 * load7;
            res3 += load6 * load7;

            ptrba += 4;
            ptrbb += 4;
        }
        // Handle remaining elements with unit-stride access
        for (k = 0; k < (temp & 1); k += 1) {
            load0 = ptrba[0];
            load1 = ptrbb[0];
            res0 += load0 * load1;
            load2 = ptrba[1];
            res1 += load2 * load1;
            load3 = ptrbb[1];
            res2 += load0 * load3;
            res3 += load2 * load3;
            ptrba += 2;
            ptrbb += 2;
        }
        res0 *= alpha; C0[0] = res0;
        res1 *= alpha; C0[1] = res1;
        res2 *= alpha; C1[0] = res2;
        res3 *= alpha; C1[1] = res3;

        temp = (bk - off - 2) * 2;
        ptrba = ptrba + temp;
        ptrbb = ptrbb + temp;
        C0 += 2;
        C1 += 2;
    }
    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k += 1) {
            load0 = ptrba[0];
            load1 = ptrbb[0];
            res0 += load0 * load1;
            load2 = ptrbb[1];
            res1 += load0 * load2;
            ptrba++;
            ptrbb += 2;
        }
        res0 *= alpha; C0[0] = res0;
        res1 *= alpha; C1[0] = res1;
        temp = bk - off - 2;
        ptrba += temp;
        ptrbb += temp * 2;
        C0++;
        C1++;
    }
    bb += (bk << 1);
    C += (ldc << 1);
}
}
