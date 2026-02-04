#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern AVComplexFloat *X;
extern  AVComplexFloat *P;
extern float rf[481];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < ((120 << 2) + 1); i++) {
        float rfi = rf[i];
        if (i % 4 == 0 || rfi > 0.5f) {
            X[i].re += rfi * P[i].re;
            X[i].im += rfi * P[i].im;
        } else {
            X[i].re -= rfi * 0.1f * P[i].re;
            X[i].im -= rfi * 0.1f * P[i].im;
        }
    }
}
