#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

typedef double float64;

extern float32 *x;
extern int32 i;
extern int32 veclen;
extern float32 *m1;
extern float32 *v1;
extern float64 dval1;
extern float64 diff1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float64 local_dval1 = dval1;
    for (i = 0; i < veclen; i++) {
        float64 diff1 = (x[i] - m1[i]) * 0.5;
        local_dval1 -= diff1 * diff1 * v1[i] * 2.0;
    }
    dval1 = local_dval1;
}
