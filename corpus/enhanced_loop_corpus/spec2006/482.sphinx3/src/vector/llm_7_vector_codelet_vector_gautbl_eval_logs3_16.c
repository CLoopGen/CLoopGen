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

        for (i = 0; i < veclen; i++) {
            float64 update1 = (x[i] - m1[i]);
            update1 *= update1 * v1[i];
            dval1 -= update1;

            float64 update2 = (x[i] - m2[i]);
            update2 *= update2 * v2[i];
            dval2 -= update2;
        }

        dval1 = (dval1 < gautbl->distfloor) ? gautbl->distfloor : dval1;
        dval2 = (dval2 < gautbl->distfloor) ? gautbl->distfloor : dval2;

        score[r] = (int32)(f * dval1);
        score[r + 1] = (int32)(f * dval2);

        dval1 = 0.0; 
        dval2 = 0.0; 
    }
}
