#include <stdio.h>

extern int k;
extern double omega;
extern double v[64][65][65][5];
extern double tv[64][64][5];
extern double udz[64][64][5][5];
extern int ist;
extern int iend;
extern int jst;
extern int jend;
extern int i;
extern int j;
extern int m;



void loop(){
for (i = iend; i >= ist; i--) {
    for (j = jend; j >= jst; j--) {
        double sum0 = 0.0, sum1 = 0.0;
        for (m = 0; m < 5; m += 2) {
            sum0 = omega * (udz[i][j][m][0] * v[i][j][k + 1][0] + 
                                   udz[i][j][m][1] * v[i][j][k + 1][1] + 
                                   udz[i][j][m][2] * v[i][j][k + 1][2] + 
                                   udz[i][j][m][3] * v[i][j][k + 1][3] + 
                                   udz[i][j][m][4] * v[i][j][k + 1][4]);
            tv[i][j][m] = sum0;
            if (m + 1 < 5) {
                sum1 = omega * (udz[i][j][m+1][0] * v[i][j][k + 1][0] + 
                                       udz[i][j][m+1][1] * v[i][j][k + 1][1] + 
                                       udz[i][j][m+1][2] * v[i][j][k + 1][2] + 
                                       udz[i][j][m+1][3] * v[i][j][k + 1][3] + 
                                       udz[i][j][m+1][4] * v[i][j][k + 1][4]);
                tv[i][j][m+1] = sum1;
            }
        }
    }
}
}
