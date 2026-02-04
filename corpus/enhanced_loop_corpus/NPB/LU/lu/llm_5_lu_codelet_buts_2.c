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
        for (m = 0; m < 5; m++) {
            double sum = 0.0;
            int n;
            for (n = 0; n < 5; n++) {
                if (udz[i][j][m][n] > 0.0) {
                    sum += udz[i][j][m][n] * v[i][j][k + 1][n];
                }
            }
            tv[i][j][m] = omega * sum;
        }
    }
}
}
