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
    for (int j = 0; j < 4; j++) {
        int offset = j * 120;
        for (int i = 0; i < 120; i++) {
            int idx = offset + i;
            if (idx < 481) {
                X[idx].re *= gf[idx];
                X[idx].im *= gf[idx];
            }
        }
    }
    // Handle remaining element at index 480
    X[480].re *= gf[480];
    X[480].im *= gf[480];
}
