#include <stdio.h>

extern  double a[64][64][5][5];
extern  double b[64][64][5][5];
extern  double c[64][64][5][5];
extern  double d[64][64][5][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (m = 0; m < 5; m++) {
    for (k = 0; k < 5; k++) {
        for (i = 0; i < 64; i++) {
            for (j = 0; j < 64; j++) {
                // Changed access order to optimize for cache reuse: loop interchange to iterate over smaller dimensions first
                // Now the inner loops traverse i and j with fixed k and m, improving spatial locality across larger arrays
                a[i][j][k][m] = 0.;
                b[i][j][k][m] = 0.;
                c[i][j][k][m] = 0.;
                d[i][j][k][m] = 0.;
            }
        }
    }
}
}
