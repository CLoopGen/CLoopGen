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
    for (i = 0; i < veclen; i += 2) {
        if (i + 1 < veclen) {
            float64 diff1_0 = x[i] - m1[i];
            float64 diff1_1 = x[i+1] - m1[i+1];
            dval1 -= diff1_0 * diff1_0 * v1[i] + diff1_1 * diff1_1 * v1[i+1];
        } else {
            float64 diff1 = x[i] - m1[i];
            dval1 -= diff1 * diff1 * v1[i];
        }
    }
}
