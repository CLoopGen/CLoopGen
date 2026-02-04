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
    ptrba = ba;
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0 = res1 = res2 = res3 = 0.0f;
        temp = off + 2;

        // Change memory access pattern to indirect indexing using precomputed indices
        // Simulate gather-like access (useful if data is non-contiguous or transposed)
        BLASLONG idx_a[8], idx_b[8];
        for (k = 0; k < temp / 4; k += 1) {
            // Precompute linear indices with stride of 2
            idx_a[0] = (2*k + 0)*2 + 0; idx_b[0] = (2*k + 0)*2 + 0;
            idx_a[1] = (2*k + 0)*2 + 1; 
            idx_a[2] = (2*k + 1)*2 + 0; idx_b[1] = (2*k + 1)*2 + 0;
            idx_a[3] = (2*k + 1)*2 + 1;
            idx_a[4] = (2*k + 2)*2 + 0; idx_b[2] = (2*k + 2)*2 + 0;
            idx_a[5] = (2*k + 2)*2 + 1;
            idx_a[6] = (2*k + 3)*2 + 0; idx_b[3] = (2*k + 3)*2 + 0;
            idx_a[7] = (2*k + 3)*2 + 1;

            // Indirect loads via index arrays
            load0 = ptrba[idx_a[0]]; load1 = ptrbb[idx_b[0]];
            res0 += load0 * load1;
            load2 = ptrba[idx_a[1]]; res1 += load2 * load1;
            load3 = ptrbb[idx_b[1]]; res2 += load0 * load3;
            res3 += load2 * load3;

            load4 = ptrba[idx_a[2]]; load5 = ptrbb[idx_b[2]];
            res0 += load4 * load5;
            load6 = ptrba[idx_a[3]]; res1 += load6 * load5;
            load7 = ptrbb[idx_b[3]]; res2 += load4 * load7;
            res3 += load6 * load7;

            // Repeat for next two pairs (fully unrolled)
            load0 = ptrba[idx_a[4]]; load1 = ptrbb[idx_b[0]+4];
            res0 += load0 * load1;
            load2 = ptrba[idx_a[5]]; res1 += load2 * load1;
            load3 = ptrbb[idx_b[1]+4]; res2 += load0 * load3;
            res3 += load2 * load3;

            load4 = ptrba[idx_a[6]]; load5 = ptrbb[idx_b[2]+4];
            res0 += load4 * load5;
            load6 = ptrba[idx_a[7]]; res1 += load6 * load5;
            load7 = ptrbb[idx_b[3]+4]; res2 += load4 * load7;
            res3 += load6 * load7;
        }

        // Remaining elements via direct indexing (fallback)
        for (k = 0; k < (temp & 3); k += 1) {
            load0 = ptrba[(temp/4*8) + 2*k + 0];
            load1 = ptrbb[2*k + 0];
            res0 += load0 * load1;
            load2 = ptrba[(temp/4*8) + 2*k + 1];
            res1 += load2 * load1;
            load3 = ptrbb[2*k + 1];
            res2 += load0 * load3;
            res3 += load2 * load3;
        }

        res0 *= alpha; C0[0] = res0;
        res1 *= alpha; C0[1] = res1;
        res2 *= alpha; C1[0] = res2;
        res3 *= alpha; C1[1] = res3;

        temp = bk - off - 2;
        ptrba += (temp + 2) * 2; // Advance base pointer
        ptrbb += (temp + 2) * 2;
        C0 += 2;
        C1 += 2;
    }

    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb;
        res0 = res1 = 0.0f;
        temp = off + 2;
        for (k = 0; k < temp; k += 1) {
            load0 = ptrba[k];               // Consecutive read from A
            load1 = ptrbb[2*k + 0];         // Strided read from B
            res0 += load0 * load1;
            load2 = ptrbb[2*k + 1];
            res1 += load0 * load2;
        }
        res0 *= alpha; C0[0] = res0;
        res1 *= alpha; C1[0] = res1;
        temp = bk - off - 2;
        ptrba += temp + 2;
        ptrbb += (temp + 2) * 2;
        C0++;
        C1++;
    }
    bb += bk * 2;
    C += ldc * 2;
}
}
