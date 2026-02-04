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
for (i = ist; i <= iend; i += 2) {
    for (j = jst; j <= jend; j += 2) {
        for (m = 0; m < 5; m++) {
            double sum = ldz[i][j][m][0] * v[i][j][k - 1][0] + 
                         ldz[i][j][m][1] * v[i][j][k - 1][1] + 
                         ldz[i][j][m][2] * v[i][j][k - 1][2];
            v[i][j][k][m] = v[i][j][k][m] - omega * sum;
            if (i+1 <= iend && j+1 <= jend) {
                sum = ldz[i+1][j+1][m][2] * v[i+1][j+1][k-1][2] + 
                      ldz[i+1][j+1][m][3] * v[i+1][j+1][k-1][3] + 
                      ldz[i+1][j+1][m][4] * v[i+1][j+1][k-1][4];
                v[i+1][j+1][k][m] = v[i+1][j+1][k][m] - omega * sum;
            }
        }
    }
}
}
