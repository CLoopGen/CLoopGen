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



void loop() {
    // Variant 2: Strided memory access with stride of 2 (mod 8 to stay in bounds)
    for (k = 0; k < 8; k++) {
        int idx = (k * 2) % 8;  // Strided access: write to every second position
        dpp->samplesA[idx] = temp_A[m];
        dpp->samplesB[idx] = temp_B[m];
        m = (m + 1) & (8 - 1);
    }
}
