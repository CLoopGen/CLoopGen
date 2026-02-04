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
    // Variant 2: Memory Access Pattern Modification - Consecutive Pointer-Based Access
    // Use pointer arithmetic to traverse arrays in a consecutive memory-access fashion.
    // Since C uses row-major order, we treat 2D arrays as 1D and access elements sequentially
    // by precomputing base offsets and stepping through memory in increasing order.
    frc1 = 0.0;
    double *p1 = &phi1[ibeg][jbeg];
    double *p2 = &phi2[ibeg][jbeg];
    int rows = 66;
    int row_len = rows;
    
    int di = 1;
    int dj = 1;
    
    for (int ii = ibeg; ii <= ifin1; ii++) {
        for (int jj = jbeg; jj <= jfin1; jj++) {
            int idx = ii * row_len + jj;
            frc1 += (p1[idx] + p1[idx + row_len] + p1[idx + 1] + p1[idx + row_len + 1] +
                     p2[idx] + p2[idx + row_len] + p2[idx + 1] + p2[idx + row_len + 1]);
        }
    }
}
