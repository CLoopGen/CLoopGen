#include <stdio.h>

extern int k;
extern double omega;
extern double v[64][65][65][5];
extern double tv[64][64][5];
extern double d[64][64][5][5];
extern double udx[64][64][5][5];
extern double udy[64][64][5][5];
extern int ist;
extern int iend;
extern int jst;
extern int jend;
extern int i;
extern int j;
extern int m;
extern double tmp;
extern double tmp1;
extern double tmat[5][5];



void loop(){
for (i = iend; i >= ist; i--) {
    for (j = jend; j >= jst; j--) {
        for (m = 0; m < 5; m++) {
            double sum = 0.0;
            for (int n = 0; n < 5; n++) {
                sum += udy[i][j][m][n] * v[i][j + 1][k][n] + udx[i][j][m][n] * v[i + 1][j][k][n];
            }
            tv[i][j][m] += omega * sum;
        }

        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                tmat[row][col] = d[i][j][row][col];
            }
        }

        for (int pivot = 0; pivot < 4; pivot++) {
            tmp1 = 1.0 / tmat[pivot][pivot];
            for (int m = pivot + 1; m < 5; m++) {
                tmp = tmp1 * tmat[m][pivot];
                for (int n = pivot + 1; n < 5; n++) {
                    tmat[m][n] -= tmp * tmat[pivot][n];
                }
                tv[i][j][m] -= tv[i][j][pivot] * tmp;
            }
        }

        for (int i_back = 4; i_back >= 0; i_back--) {
            double sum = 0.0;
            for (int k_back = i_back + 1; k_back < 5; k_back++) {
                sum += tmat[i_back][k_back] * tv[i][j][k_back];
            }
            tv[i][j][i_back] = (tv[i][j][i_back] - sum) / tmat[i_back][i_back];
        }

        for (int m = 0; m < 5; m++) {
            v[i][j][k][m] -= tv[i][j][m];
        }
    }
}
}
