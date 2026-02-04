#include <stdio.h>

extern int nz0;
extern int ist;
extern int iend;
extern int jst;
extern int jend;
extern double v[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern double sum0;
extern double sum1;
extern double sum2;
extern double sum3;
extern double sum4;



void loop(){
for (i = ist; i <= iend; i++) {
    for (j = jst; j <= jend; j++) {
        for (k = 1; k <= nz0 - 2; k++) {
            if (v[i][j][k][0] >= 0.0) {
                sum0 = sum0 + v[i][j][k][0] * v[i][j][k][0];
            }
            if (v[i][j][k][1] >= 0.0) {
                sum1 = sum1 + v[i][j][k][1] * v[i][j][k][1];
            }
            if (v[i][j][k][2] >= 0.0) {
                sum2 = sum2 + v[i][j][k][2] * v[i][j][k][2];
            }
            if (v[i][j][k][3] >= 0.0) {
                sum3 = sum3 + v[i][j][k][3] * v[i][j][k][3];
            }
            if (v[i][j][k][4] >= 0.0) {
                sum4 = sum4 + v[i][j][k][4] * v[i][j][k][4];
            }
        }
    }
}
}
