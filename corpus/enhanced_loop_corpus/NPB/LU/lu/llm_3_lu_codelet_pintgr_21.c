#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern int i;
extern int k;
extern int ibeg;
extern int ifin1;
extern double phi1[66][66];
extern double phi2[66][66];
extern double frc2;



void loop(){
    // Variant 2: Memory Access Pattern Modification - Consecutive Access via Linear Indexing (flatten 2D indices into pseudo-1D pattern)
    // Use row-major order simulation: treat each row as a contiguous block
    int base_i, offset_k;
    for (i = ibeg; i <= ifin1; i++) {
        base_i = i * 66;  // Assuming fixed size 66 as per declaration
        for (k = ki1; k <= ki2 - 1; k++) {
            offset_k = k;
            // Access elements using calculated linear-like offsets to promote cache-friendly consecutive behavior
            frc2 = frc2 + (
                phi1[base_i / 66][offset_k] +
                phi1[base_i / 66 + 1][offset_k] +
                phi1[base_i / 66][offset_k + 1] +
                phi1[base_i / 66 + 1][offset_k + 1] +
                phi2[base_i / 66][offset_k] +
                phi2[base_i / 66 + 1][offset_k] +
                phi2[base_i / 66][offset_k + 1] +
                phi2[base_i / 66 + 1][offset_k + 1]
            );
        }
    }
}
