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
int32 outer_i;
int32 inner_i;
for (outer_i = 0; outer_i < veclen; outer_i += 2) {
    for (inner_i = 0; inner_i < 2 && (outer_i + inner_i) < veclen; inner_i++) {
        i = outer_i + inner_i;
        diff1 = x[i] - m1[i];
        dval1 -= diff1 * diff1 * v1[i];
    }
}
}
