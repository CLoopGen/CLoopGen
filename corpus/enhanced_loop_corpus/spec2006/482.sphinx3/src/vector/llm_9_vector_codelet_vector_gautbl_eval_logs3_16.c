#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef float float32;

typedef double float64;

typedef struct {
    int32 n_gau;
    int32 veclen;
    float32 **mean;
    float32 **var;
    float32 *lrd;
    float64 distfloor;
} vector_gautbl_t;

extern vector_gautbl_t *gautbl;
extern int32 offset;
extern float32 *x;
extern int32 *score;
extern int32 i;
extern int32 r;
extern float64 f;
extern int32 end;
extern int32 veclen;
extern float32 *m1;
extern float32 *m2;
extern float32 *v1;
extern float32 *v2;
extern float64 dval1;
extern float64 dval2;
extern float64 diff1;
extern float64 diff2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased work per outer iteration (blocking).
    // Process four Gaussian components at once instead of two, reducing outer loop iterations.
    // Assumes 'end' is aligned to 4 and offset is even for correctness.
    for (r = offset; r < end - 3; r += 4) {
        // Process r, r+1, r+2, r+3 in groups
        float32 *m3 = gautbl->mean[r + 2];
        float32 *m4 = gautbl->mean[r + 3];
        float32 *v3 = gautbl->var[r + 2];
        float32 *v4 = gautbl->var[r + 3];
        float64 dval3 = gautbl->lrd[r + 2];
        float64 dval4 = gautbl->lrd[r + 3];

        m1 = gautbl->mean[r];
        m2 = gautbl->mean[r + 1];
        v1 = gautbl->var[r];
        v2 = gautbl->var[r + 1];
        dval1 = gautbl->lrd[r];
        dval2 = gautbl->lrd[r + 1];

        for (i = 0; i < veclen; i++) {
            diff1 = x[i] - m1[i];
            dval1 -= diff1 * diff1 * v1[i];
            diff2 = x[i] - m2[i];
            dval2 -= diff2 * diff2 * v2[i];
            diff1 = x[i] - m3[i];  // Reuse diff1 for temp storage
            dval3 -= diff1 * diff1 * v3[i];
            diff2 = x[i] - m4[i];  // Reuse diff2
            dval4 -= diff2 * diff2 * v4[i];
        }

        if (dval1 < gautbl->distfloor) dval1 = gautbl->distfloor;
        if (dval2 < gautbl->distfloor) dval2 = gautbl->distfloor;
        if (dval3 < gautbl->distfloor) dval3 = gautbl->distfloor;
        if (dval4 < gautbl->distfloor) dval4 = gautbl->distfloor;

        score[r]     = (int32)(f * dval1);
        score[r + 1] = (int32)(f * dval2);
        score[r + 2] = (int32)(f * dval3);
        score[r + 3] = (int32)(f * dval4);
    }

    // Handle leftover elements (if any) with original pairwise logic
    for (; r < end - 1; r += 2) {
        m1 = gautbl->mean[r];
        m2 = gautbl->mean[r + 1];
        v1 = gautbl->var[r];
        v2 = gautbl->var[r + 1];
        dval1 = gautbl->lrd[r];
        dval2 = gautbl->lrd[r + 1];
        for (i = 0; i < veclen; i++) {
            diff1 = x[i] - m1[i];
            dval1 -= diff1 * diff1 * v1[i];
            diff2 = x[i] - m2[i];
            dval2 -= diff2 * diff2 * v2[i];
        }
        if (dval1 < gautbl->distfloor) dval1 = gautbl->distfloor;
        if (dval2 < gautbl->distfloor) dval2 = gautbl->distfloor;
        score[r] = (int32)(f * dval1);
        score[r + 1] = (int32)(f * dval2);
    }
}
