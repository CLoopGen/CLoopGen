#include <stdio.h>

extern  int nx;
extern  int ny;
extern  int nz;
extern  double frct[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 1: Change memory access pattern to stride by 2 in the k-dimension, then handle remainder
    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            for (m = 0; m < 5; m++) {
                for (k = 0; k < nz; k += 2) {
                    frct[i][j][k][m] = 0.;
                    if (k + 1 < nz) {
                        frct[i][j][k+1][m] = 0.;
                    }
                }
            }
        }
    }
}
