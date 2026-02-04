#include <stdio.h>

extern int k;
extern double omega;
extern double v[64][65][65][5];
extern double ldz[64][64][5][5];
extern int ist;
extern int iend;
extern int jst;
extern int jend;
extern int i;
extern int j;
extern int m;



void loop(){
// Change memory access pattern to stride through 'm' first, then spatial indices
// This creates a more strided access to v[i][j][k][m] and ldz[i][j][m][*]
for (m = 0; m < 5; m++) {
    for (i = ist; i <= iend; i++) {
        for (j = jst; j <= jend; j++) {
            double sum = ldz[i][j][m][0] * v[i][j][k - 1][0] +
                         ldz[i][j][m][1] * v[i][j][k - 1][1] +
                         ldz[i][j][m][2] * v[i][j][k - 1][2] +
                         ldz[i][j][m][3] * v[i][j][k - 1][3] +
                         ldz[i][j][m][4] * v[i][j][k - 1][4];
            v[i][j][k][m] = v[i][j][k][m] - omega * sum;
        }
    }
}
}
