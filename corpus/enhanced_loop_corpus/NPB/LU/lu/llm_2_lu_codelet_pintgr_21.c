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
    // Variant 1: Memory Access Pattern Modification - Strided Access with Increased Stride (simulated by accessing every second element)
    // Adjusted bounds to prevent out-of-bounds access when skipping elements
    for (i = ibeg; i <= ifin1; i++) {
        for (k = ki1; k <= ki2 - 2; k += 2) {  // Stride of 2 to create strided memory access
            frc2 = frc2 + (phi1[i][k] + phi1[i + 1][k] + phi1[i][k + 1] + phi1[i + 1][k + 1] +
                          phi2[i][k] + phi2[i + 1][k] + phi2[i][k + 1] + phi2[i + 1][k + 1]);
        }
    }
}
