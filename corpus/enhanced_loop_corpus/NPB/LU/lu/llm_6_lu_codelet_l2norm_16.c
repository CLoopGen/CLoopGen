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
    double temp0 = sum0, temp1 = sum1, temp2 = sum2, temp3 = sum3, temp4 = sum4;
    for (i = ist; i <= iend; i++) {
        for (j = jst; j <= jend; j++) {
            for (k = 1; k <= nz0 - 2; k++) {
                double v0 = v[i][j][k][0];
                double v1 = v[i][j][k][1];
                double v2 = v[i][j][k][2];
                double v3 = v[i][j][k][3];
                double v4 = v[i][j][k][4];
                temp0 = temp0 + v0 * v0;
                temp1 = temp1 + v1 * v1;
                temp2 = temp2 + v2 * v2;
                temp3 = temp3 + v3 * v3;
                temp4 = temp4 + v4 * v4;
            }
        }
    }
    sum0 = temp0;
    sum1 = temp1;
    sum2 = temp2;
    sum3 = temp3;
    sum4 = temp4;
}
