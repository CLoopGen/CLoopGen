#include <stdio.h>

int ist = 0;
int iend = 63;
int jst = 0;
int jend = 63;
double tx1 = 0.1;
double tx2 = 0.2;
double ty1 = 0.1;
double ty2 = 0.2;
double tz1 = 0.1;
double tz2 = 0.2;
double dx1 = 0.01;
double dx2 = 0.02;
double dx3 = 0.03;
double dx4 = 0.04;
double dx5 = 0.05;
double dy1 = 0.01;
double dy2 = 0.02;
double dy3 = 0.03;
double dy4 = 0.04;
double dy5 = 0.05;
double dz1 = 0.01;
double dz2 = 0.02;
double dz3 = 0.03;
double dz4 = 0.04;
double dz5 = 0.05;
double u[64][65][65][5];
double dt = 0.001;
double a[64][64][5][5];
double b[64][64][5][5];
double c[64][64][5][5];
double d[64][64][5][5];
int k = 0;
int i = 0;
int j = 0;
double r43 = 1.3333333333333333;
double c1345 = 0.1345;
double c34 = 0.34;
double tmp1 = 0.0;
double tmp2 = 0.0;
double tmp3 = 0.0;

void init_vars() {
    for (int i_idx = 0; i_idx < 64; ++i_idx) {
        for (int j_idx = 0; j_idx < 65; ++j_idx) {
            for (int k_idx = 0; k_idx < 65; ++k_idx) {
                u[i_idx][j_idx][k_idx][0] = 1.0 + 0.1 * i_idx;
                u[i_idx][j_idx][k_idx][1] = 0.1 * j_idx;
                u[i_idx][j_idx][k_idx][2] = 0.1 * k_idx;
                u[i_idx][j_idx][k_idx][3] = 0.05 * i_idx;
                u[i_idx][j_idx][k_idx][4] = 2.0 + 0.01 * (i_idx + j_idx + k_idx);
            }
        }
    }

    for (int i_idx = 0; i_idx < 64; ++i_idx) {
        for (int j_idx = 0; j_idx < 64; ++j_idx) {
            for (int m = 0; m < 5; ++m) {
                for (int n = 0; n < 5; ++n) {
                    a[i_idx][j_idx][m][n] = 0.0;
                    b[i_idx][j_idx][m][n] = 0.0;
                    c[i_idx][j_idx][m][n] = 0.0;
                    d[i_idx][j_idx][m][n] = 0.0;
                }
            }
        }
    }

    ist = 0;
    iend = 62;
    jst = 0;
    jend = 62;
    k = 0;
}