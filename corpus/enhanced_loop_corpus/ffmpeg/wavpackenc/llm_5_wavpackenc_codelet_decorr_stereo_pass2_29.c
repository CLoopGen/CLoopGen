#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct Decorr {
    int delta;
    int value;
    int weightA;
    int weightB;
    int samplesA[8];
    int samplesB[8];
    int sumA;
    int sumB;
};


extern struct Decorr *dpp;
extern int m;
extern int k;
extern int32_t temp_A[8];
extern int32_t temp_B[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 8; k++) {
        dpp->samplesA[k] = temp_A[m];
        dpp->samplesB[k] = temp_B[m];
        m = (m + 1) & (8 - 1);
        if (k == 3) {
            break;
        }
    }
}
