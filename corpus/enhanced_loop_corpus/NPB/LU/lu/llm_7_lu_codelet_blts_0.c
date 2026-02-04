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
for (i = ist; i <= iend; i++) {
    for (j = jst; j <= jend; j++) {
        double sum0 = v[i][j][k - 1][0], sum1 = v[i][j][k - 1][1], 
               sum2 = v[i][j][k - 1][2], sum3 = v[i][j][k - 1][3], 
               sum4 = v[i][j][k - 1][4];
        for (m = 0; m < 5; m++) {
            double dot = ldz[i][j][m][0] * sum0 + 
                         ldz[i][j][m][1] * sum1 + 
                         ldz[i][j][m][2] * sum2 + 
                         ldz[i][j][m][3] * sum3 + 
                         ldz[i][j][m][4] * sum4;
            v[i][j][k][m] = v[i][j][k][m] - omega * dot;
        }
    }
}
}
