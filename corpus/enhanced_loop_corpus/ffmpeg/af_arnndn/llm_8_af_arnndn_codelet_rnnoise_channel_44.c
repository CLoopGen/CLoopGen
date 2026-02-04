#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern AVComplexFloat X[481];
extern float gf[481];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < ((120 << 2) + 1); i += 2) {
        X[i].re *= gf[i];
        X[i].im *= gf[i];
        if (i + 1 < ((120 << 2) + 1)) {
            X[i+1].re *= gf[i+1];
            X[i+1].im *= gf[i+1];
        }
    }
}
