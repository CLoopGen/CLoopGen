#include <stdio.h>

int ist = 1;
int iend = 62;
int jst = 1;
int jend = 63;
int k = 1;
int i;
int j;

double tx1 = 0.1;
double tx2 = 0.2;
double ty1 = 0.15;
double ty2 = 0.25;
double tz1 = 0.12;
double tz2 = 0.22;
double dx1 = 0.01;
double dx2 = 0.02;
double dx3 = 0.03;
double dx4 = 0.04;
double dx5 = 0.05;
double dy1 = 0.011;
double dy2 = 0.021;
double dy3 = 0.031;
double dy4 = 0.041;
double dy5 = 0.051;
double dz1 = 0.012;
double dz2 = 0.022;
double dz3 = 0.032;
double dz4 = 0.042;
double dz5 = 0.052;
double dt = 0.001;
double r43 = 1.3333333333333333;
double c1345 = 1.345;
double c34 = 0.34;
double tmp1;
double tmp2;
double tmp3;

double u[64][65][65][5];
double a[64][64][5][5];
double b[64][64][5][5];
double c[64][64][5][5];
double d[64][64][5][5];

void init_vars() {
    for (int i_idx = 0; i_idx < 64; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                double rho = 1.0 + 0.1 * i_idx;
                double vx = 0.1 * j_idx;
                double vy = 0.1 * k_idx;
                double vz = 0.05 * (i_idx + j_idx);
                double e = 2.5 + 0.1 * (i_idx + j_idx + k_idx);
                u[i_idx][j_idx][k_idx][0] = rho;
                u[i_idx][j_idx][k_idx][1] = rho * vx;
                u[i_idx][j_idx][k_idx][2] = rho * vy;
                u[i_idx][j_idx][k_idx][3] = rho * vz;
                u[i_idx][j_idx][k_idx][4] = e + 0.5 * rho * (vx*vx + vy*vy + vz*vz);
            }
        }
    }

    for (int i_idx = 0; i_idx < 64; i_idx++) {
        for (int j_idx = 0; j_idx < 64; j_idx++) {
            for (int m = 0; m < 5; m++) {
                for (int n = 0; n < 5; n++) {
                    a[i_idx][j_idx][m][n] = 0.0;
                    b[i_idx][j_idx][m][n] = 0.0;
                    c[i_idx][j_idx][m][n] = 0.0;
                    d[i_idx][j_idx][m][n] = 0.0;
                }
            }
        }
    }
}