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
    for (int j = 0; j < 4; j++) {
        int offset = j * 120;
        for (int i = 0; i < 120; i++) {
            int idx = offset + i;
            if (idx >= ((120 << 2) + 1)) break;
            X[idx].re += rf[idx] * P[idx].re;
            X[idx].im += rf[idx] * P[idx].im;
        }
    }
    // Handle the remaining element if any (since 4*120 + 1 = 481)
    int last_idx = (120 << 2);
    X[last_idx].re += rf[last_idx] * P[last_idx].re;
    X[last_idx].im += rf[last_idx] * P[last_idx].im;
}
