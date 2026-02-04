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
        v1 = gautbl->var[r];
        dval1 = gautbl->lrd[r];
        m2 = gautbl->mean[r + 1];
        v2 = gautbl->var[r + 1];
        dval2 = gautbl->lrd[r + 1];

        float64 temp_dval1 = dval1;
        float64 temp_dval2 = dval2;

        for (i = 0; i < veclen; i++) {
            float64 temp_diff1 = x[i] - m1[i];
            float64 temp_diff2 = x[i] - m2[i];
            temp_dval1 -= temp_diff1 * temp_diff1 * v1[i];
            temp_dval2 -= temp_diff2 * temp_diff2 * v2[i];
        }

        if (temp_dval1 < gautbl->distfloor)
            temp_dval1 = gautbl->distfloor;
        if (temp_dval2 < gautbl->distfloor)
            temp_dval2 = gautbl->distfloor;

        score[r] = (int32)(f * temp_dval1);
        score[r + 1] = (int32)(f * temp_dval2);
    }
}
