#include <stdio.h>

int nz = 64;
int ist = 1;
int iend = 62;
int jst = 1;
int jend = 62;
double tz1 = 0.1;
double tz2 = 0.2;
double tz3 = 0.3;
double dz1 = 0.05;
double dz2 = 0.06;
double dz3 = 0.07;
double dz4 = 0.08;
double dz5 = 0.09;
double rsd[64][65][65][5];
double frct[64][65][65][5];
double flux[64][65][65][5];
int i;
int j;
int k;
int m;
double dsspm = 0.01;
double q;
double u41;
double tmp;
double u21k;
double u31k;
double u41k;
double u51k;
double u21km1;
double u31km1;
double u41km1;
double u51km1;

void init_vars() {
    for (int i0 = 0; i0 < 64; i0++) {
        for (int j0 = 0; j0 < 65; j0++) {
            for (int k0 = 0; k0 < 65; k0++) {
                for (int m0 = 0; m0 < 5; m0++) {
                    rsd[i0][j0][k0][m0] = (double)(i0 + j0 + k0 + m0 + 1) * 0.01;
                    frct[i0][j0][k0][m0] = (double)(i0 + j0 + k0 + m0 + 2) * 0.02;
                    flux[i0][j0][k0][m0] = 0.0;
                }
            }
        }
    }
    nz = 64;
    ist = 1;
    iend = 62;
    jst = 1;
    jend = 62;
    tz1 = 0.1;
    tz2 = 0.2;
    tz3 = 0.3;
    dz1 = 0.05;
    dz2 = 0.06;
    dz3 = 0.07;
    dz4 = 0.08;
    dz5 = 0.09;
    dsspm = 0.01;
}