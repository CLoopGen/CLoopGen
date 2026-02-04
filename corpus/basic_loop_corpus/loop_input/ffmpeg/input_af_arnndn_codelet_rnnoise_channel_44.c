#include <stdlib.h>
#include <math.h>

typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

AVComplexFloat X[481];
float gf[481];

void init_vars() {
    for (int i = 0; i < 481; i++) {
        X[i].re = 1.0f;
        X[i].im = 1.0f;
        gf[i] = 2.0f;
    }
}