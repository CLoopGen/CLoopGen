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
        for (m = 0; m < 5; m++) {
            double sum = 0.0;
            for (int n = 0; n < 5; n++) {
                sum += ldz[i][j][m][n] * v[i][j][k - 1][n];
            }
            v[i][j][k][m] = v[i][j][k][m] - omega * sum;
        }
    }
}
}
