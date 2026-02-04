#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern int j;
extern int k;
extern int jbeg;
extern int jfin1;
extern double phi1[66][66];
extern double phi2[66][66];
extern double frc3;



void loop(){
    // Variant 2: Use consecutive row-major linear indexing (flatten 2D access into sequential strides)
    int rows = 66;
    for (j = jbeg; j <= jfin1; j++) {
        for (k = ki1; k <= ki2 - 1; k++) {
            int base_idx = j * rows + k;
            int base_idx_jp1 = (j + 1) * rows + k;
            frc3 = frc3 + (
                phi1[0][base_idx] + phi1[0][base_idx_jp1] + 
                phi1[0][base_idx + 1] + phi1[0][base_idx_jp1 + 1] +
                phi2[0][base_idx] + phi2[0][base_idx_jp1] + 
                phi2[0][base_idx + 1] + phi2[0][base_idx_jp1 + 1]
            );
        }
    }
}
