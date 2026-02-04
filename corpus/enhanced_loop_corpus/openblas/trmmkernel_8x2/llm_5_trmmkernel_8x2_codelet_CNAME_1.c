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
extern float a0;
extern float a1;
extern float b0;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn & 1); j += 1) {
    C0 = C;
    ptrba = ba;

    // Unify all block sizes into single loop with stride control via lookup
    BLASLONG strides[] = {8, 4, 2, 1};
    BLASLONG counts[] = {bm / 8, (bm & 4) ? 1 : 0, (bm & 2) ? 1 : 0, (bm & 1) ? 1 : 0};
    float *res_ptrs[] = {&res0_0, &res0_1, &res0_2, &res0_3, &res0_4, &res0_5, &res0_6, &res0_7};

    for (BLASLONG s = 0; s < 4; s++) {
        BLASLONG stride = strides[s];
        BLASLONG count = counts[s];

        for (i = 0; i < count; i++) {
            ptrbb = bb;
            // Reset accumulators based on current stride
            for (BLASLONG r = 0; r < stride; r++) {
                *(res_ptrs[r]) = 0.0f;
            }

            temp = off + 1;
            for (k = 0; k < temp; k++) {
                b0 = ptrbb[0];
                for (BLASLONG a = 0; a < stride; a++) {
                    float val = ptrba[a];
                    *(res_ptrs[a]) += val * b0;
                }
                ptrba += stride;
                ptrbb += 1;
            }

            // Scale and store results
            for (BLASLONG r = 0; r < stride; r++) {
                *(res_ptrs[r]) *= alpha;
                C0[r] = *(res_ptrs[r]);
            }

            temp = bk - off - 1;
            ptrba += temp * stride;
            ptrbb += temp * 1;
            C0 += stride;
        }
    }

    k = bk;
    bb = bb + k;
    C = C + ldc;
}
}
