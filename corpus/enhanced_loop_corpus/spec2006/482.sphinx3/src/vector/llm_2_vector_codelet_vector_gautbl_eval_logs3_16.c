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
for (r = offset; r < end - 1; r += 2) {
    m1 = gautbl->mean[r];
    m2 = gautbl->mean[r + 1];
    v1 = gautbl->var[r];
    v2 = gautbl->var[r + 1];
    dval1 = gautbl->lrd[r];
    dval2 = gautbl->lrd[r + 1];
    i = 0;
    for (; i < veclen - 3; i += 4) {
        diff1 = x[i] - m1[i];
        dval1 -= diff1 * diff1 * v1[i];
        diff2 = x[i] - m2[i];
        dval2 -= diff2 * diff2 * v2[i];

        diff1 = x[i+1] - m1[i+1];
        dval1 -= diff1 * diff1 * v1[i+1];
        diff2 = x[i+1] - m2[i+1];
        dval2 -= diff2 * diff2 * v2[i+1];

        diff1 = x[i+2] - m1[i+2];
        dval1 -= diff1 * diff1 * v1[i+2];
        diff2 = x[i+2] - m2[i+2];
        dval2 -= diff2 * diff2 * v2[i+2];

        diff1 = x[i+3] - m1[i+3];
        dval1 -= diff1 * diff1 * v1[i+3];
        diff2 = x[i+3] - m2[i+3];
        dval2 -= diff2 * diff2 * v2[i+3];
    }
    for (; i < veclen; i++) {
        diff1 = x[i] - m1[i];
        dval1 -= diff1 * diff1 * v1[i];
        diff2 = x[i] - m2[i];
        dval2 -= diff2 * diff2 * v2[i];
    }
    if (dval1 < gautbl->distfloor)
        dval1 = gautbl->distfloor;
    if (dval2 < gautbl->distfloor)
        dval2 = gautbl->distfloor;
    score[r] = (int32)(f * dval1);
    score[r + 1] = (int32)(f * dval2);
}
}
