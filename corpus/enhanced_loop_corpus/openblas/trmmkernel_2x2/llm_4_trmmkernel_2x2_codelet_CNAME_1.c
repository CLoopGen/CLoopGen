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
extern float res0;
extern float res1;
extern float load0;
extern float load1;
extern float load2;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < (bn & 1); j += 1) {
        C0 = C;
        ptrba = ba;
        i = 0;
        if (bm >= 2) {
            for (; i < bm - 1; i += 2) {
                ptrbb = bb;
                res0 = 0;
                res1 = 0;
                temp = off + 1;
                k = 0;
                for (; k < temp; k++) {
                    load0 = ptrba[0];
                    load1 = ptrbb[0];
                    res0 += load0 * load1;
                    load2 = ptrba[1];
                    res1 += load2 * load1;
                    ptrba += 2;
                    ptrbb++;
                }
                res0 *= alpha;
                res1 *= alpha;
                C0[0] = res0;
                C0[1] = res1;
                temp = bk - off - 1;
                ptrba += temp * 2;
                ptrbb += temp;
                C0 += 2;
            }
        }
        if (i < bm) {
            ptrbb = bb;
            res0 = 0;
            temp = off + 1;
            for (k = 0; k < temp; k++) {
                load0 = ptrba[0];
                load1 = ptrbb[0];
                res0 += load0 * load1;
                ptrba++;
                ptrbb++;
            }
            res0 *= alpha;
            C0[0] = res0;
            temp = bk - off - 1;
            ptrba += temp;
            ptrbb += temp;
            C0++;
        }
        bb += bk;
        C += ldc;
    }
}
