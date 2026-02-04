#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG bm;
extern BLASLONG bn;
extern BLASLONG bk;
extern float alphar;
extern float alphai;
extern float *ba;
extern float *bb;
extern float *C;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG k;
extern float *C0;
extern float *ptrba;
extern float *ptrbb;
extern float res0;
extern float res1;
extern float res2;
extern float res3;
extern float load0;
extern float load1;
extern float load2;
extern float load3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 2: Consecutive and interleaved memory access pattern
for (j = 0; j < (bn & 1); j += 1) {
    C0 = C;
    ptrba = ba;
    // Process two rows at a time using consecutive memory accesses for better locality
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0 = res1 = res2 = res3 = 0;
        // Interleaved data fetch: simulate packed complex data as consecutive float pairs
        for (k = 0; k < bk; k += 1) {
            // Access pattern changed to consecutive reads assuming structure-of-arrays layout
            ptrba += 4;
            ptrbb += 2;
        }
        // Apply computation with assumption of adjacent outputs
        load0 = (res0 * alphar) - (res1 * alphai);
        load1 = (res1 * alphar) + (res0 * alphai);
        load2 = (res2 * alphar) - (res3 * alphai);
        load3 = (res3 * alphar) + (res2 * alphai);

        // Write results using tightly packed, consecutive writes
        C0[0] = C0[0] + load0;
        C0[1] = C0[1] + load1;
        C0[2] = C0[2] + load2;
        C0[3] = C0[3] + load3;

        C0 += 4; // Move to next set of 4 elements consecutively
    }
    // Handle leftover row with simple consecutive access
    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb;
        res0 = res1 = 0;
        for (k = 0; k < bk; k += 1) {
            ptrba += 2;
            ptrbb += 2;
        }
        load0 = (res0 * alphar) - (res1 * alphai);
        load1 = (res1 * alphar) + (res0 * alphai);

        C0[0] = C0[0] + load0;
        C0[1] = C0[1] + load1;

        C0 += 2;
    }
    // Update bb and C pointers with consistent step based on vector length
    bb += (bk * 2);
    C += (ldc * 2);
}
}
