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
for (i = iend; i >= ist; i -= 2) {
    for (j = jend; j >= jst; j -= 2) {
        double tv_cache[2][2][5] = {0};
        double tmat_cache[2][2][5][5] = {0};
        for (int ii = 0; ii < 2 && (i - ii) >= ist; ii++) {
            for (int jj = 0; jj < 2 && (j - jj) >= jst; jj++) {
                int ci = i - ii;
                int cj = j - jj;
                for (m = 0; m < 5; m++) {
                    tv_cache[ii][jj][m] = tv[ci][cj][m] + omega * (
                        udy[ci][cj][m][0] * v[ci][cj + 1][k][0] + 
                        udx[ci][cj][m][0] * v[ci + 1][cj][k][0] + 
                        udy[ci][cj][m][1] * v[ci][cj + 1][k][1] + 
                        udx[ci][cj][m][1] * v[ci + 1][cj][k][1] + 
                        udy[ci][cj][m][2] * v[ci][cj + 1][k][2] + 
                        udx[ci][cj][m][2] * v[ci + 1][cj][k][2] + 
                        udy[ci][cj][m][3] * v[ci][cj + 1][k][3] + 
                        udx[ci][cj][m][3] * v[ci + 1][cj][k][3] + 
                        udy[ci][cj][m][4] * v[ci][cj + 1][k][4] + 
                        udx[ci][cj][m][4] * v[ci + 1][cj][k][4]
                    );
                    for (int n = 0; n < 5; n++) {
                        tmat_cache[ii][jj][m][n] = d[ci][cj][m][n];
                    }
                }
                double local_tmat[5][5];
                double local_tv[5];
                for (m = 0; m < 5; m++) {
                    for (int n = 0; n < 5; n++) {
                        local_tmat[m][n] = tmat_cache[ii][jj][m][n];
                    }
                    local_tv[m] = tv_cache[ii][jj][m];
                }
                double tmp1 = 1.0 / local_tmat[0][0];
                for (m = 1; m < 5; m++) {
                    double tmp = tmp1 * local_tmat[m][0];
                    for (int n = 1; n < 5; n++) {
                        local_tmat[m][n] -= tmp * local_tmat[0][n];
                    }
                    local_tv[m] -= local_tv[0] * tmp;
                }
                for (int k_step = 1; k_step < 4; k_step++) {
                    if (local_tmat[k_step][k_step] == 0.0) continue;
                    tmp1 = 1.0 / local_tmat[k_step][k_step];
                    for (m = k_step + 1; m < 5; m++) {
                        double tmp = tmp1 * local_tmat[m][k_step];
                        for (int n = k_step + 1; n < 5; n++) {
                            local_tmat[m][n] -= tmp * local_tmat[k_step][n];
                        }
                        local_tv[m] -= local_tv[k_step] * tmp;
                    }
                }
                for (m = 4; m >= 0; m--) {
                    double sum = 0.0;
                    for (int n = m + 1; n < 5; n++) {
                        sum += local_tmat[m][n] * local_tv[n];
                    }
                    local_tv[m] = (local_tv[m] - sum) / local_tmat[m][m];
                }
                for (m = 0; m < 5; m++) {
                    v[ci][cj][k][m] -= local_tv[m];
                }
            }
        }
    }
}
}
