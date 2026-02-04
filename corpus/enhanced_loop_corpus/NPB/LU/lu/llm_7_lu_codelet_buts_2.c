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
double prev_sum = 0.0;
for (i = iend; i >= ist; i--) {
    for (j = jend; j >= jst; j--) {
        for (m = 0; m < 5; m++) {
            double dot_product = udz[i][j][m][0] * v[i][j][k + 1][0] +
                                 udz[i][j][m][1] * v[i][j][k + 1][1] +
                                 udz[i][j][m][2] * v[i][j][k + 1][2] +
                                 udz[i][j][m][3] * v[i][j][k + 1][3] +
                                 udz[i][j][m][4] * v[i][j][k + 1][4];
            tv[i][j][m] = omega * dot_product + prev_sum;
            prev_sum = dot_product;
        }
    }
}
}
