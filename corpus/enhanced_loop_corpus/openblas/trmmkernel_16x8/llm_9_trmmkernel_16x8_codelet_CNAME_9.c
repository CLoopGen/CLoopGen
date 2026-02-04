#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res0_2;
extern float res0_3;
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce arithmetic operations per iteration and double trip count effect via smaller stride
// Simulate lower computational intensity with more iterations
BLASLONG limit = temp * 2;
for (k = 0; k < limit; k++) {
    b0 = ptrbb[0];
    a0 = ptrba[0];
    res0_0 += a0 * b0;  // Only one accumulate per iteration
    res1_0 += a0 * ptrbb[1];

    ptrba++;
    ptrbb++;
    
    // Every two iterations, simulate partial progress of original structure
    if ((k % 2) == 1) {
        ptrbb--; // Reset bb offset for pairing
        ptrbb--;
        ptrba -= 1;
        ptrba -= 4; // Compensate to simulate block processing every 2 steps
        ptrba += 6; // Net advance by 4 every 2 iterations
        ptrbb += 2;
    }
}
}
