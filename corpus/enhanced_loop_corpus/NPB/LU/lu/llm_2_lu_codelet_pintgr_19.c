#include <stdio.h>

extern int i;
extern int j;
extern int ibeg;
extern int ifin1;
extern int jbeg;
extern int jfin1;
extern double phi1[66][66];
extern double phi2[66][66];
extern double frc1;



void loop(){
    // Variant 1: Memory Access Pattern Modification - Strided Access with Row-Major Optimization
    // We change the access pattern by transposing the iteration order to column-major-like (j outer, i inner)
    // This creates a strided access pattern for phi1 and phi2 in the original i-dimension,
    // increasing spatial locality in j-direction and altering cache behavior.
    frc1 = 0.0; // Initialize to avoid undefined behavior
    for (j = jbeg; j <= jfin1; j++) {
        for (i = ibeg; i <= ifin1; i++) {
            frc1 += (phi1[i][j] + phi1[i + 1][j] + phi1[i][j + 1] + phi1[i + 1][j + 1] +
                     phi2[i][j] + phi2[i + 1][j] + phi2[i][j + 1] + phi2[i + 1][j + 1]);
        }
    }
}
