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
for (i = iend; i >= ist; i -= 2) {
    for (j = jend; j >= jst; j -= 2) {
        for (m = 0; m < 5; m++) {
            tv[i][j][m] = omega * (
                udz[i][j][m][0] * v[i][j][k + 1][0] + 
                udz[i][j][m][1] * v[i][j][k + 1][1] + 
                udz[i][j][m][2] * v[i][j][k + 1][2]
            );
            if (i > ist && j > jst) {
                tv[i-1][j][m] = omega * (
                    udz[i-1][j][m][0] * v[i-1][j][k + 1][0] + 
                    udz[i-1][j][m][1] * v[i-1][j][k + 1][1] + 
                    udz[i-1][j][m][2] * v[i-1][j][k + 1][2] + 
                    udz[i-1][j][m][3] * v[i-1][j][k + 1][3] + 
                    udz[i-1][j][m][4] * v[i-1][j][k + 1][4]
                );
                tv[i][j-1][m] = omega * (
                    udz[i][j-1][m][0] * v[i][j-1][k + 1][0] + 
                    udz[i][j-1][m][1] * v[i][j-1][k + 1][1] + 
                    udz[i][j-1][m][2] * v[i][j-1][k + 1][2] + 
                    udz[i][j-1][m][3] * v[i][j-1][k + 1][3] + 
                    udz[i][j-1][m][4] * v[i][j-1][k + 1][4]
                );
                tv[i-1][j-1][m] = omega * (
                    udz[i-1][j-1][m][0] * v[i-1][j-1][k + 1][0] + 
                    udz[i-1][j-1][m][1] * v[i-1][j-1][k + 1][1] + 
                    udz[i-1][j-1][m][2] * v[i-1][j-1][k + 1][2]
                );
            }
        }
    }
}
}
