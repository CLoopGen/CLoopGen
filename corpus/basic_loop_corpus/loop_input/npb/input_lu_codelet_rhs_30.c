#include <stdio.h>

int nx = 64;
int nz = 65;
int ist = 2;
int iend = 62;
int jst = 1;
int jend = 63;
double tx1 = 1.0;
double tx2 = 1.5;
double tx3 = 2.0;
double dx1 = 0.1;
double dx2 = 0.15;
double dx3 = 0.2;
double dx4 = 0.25;
double dx5 = 0.3;
double dssp = 0.05;

double u[64][65][65][5];
double rsd[64][65][65][5];
double flux[64][65][65][5];

int i, j, k, m;
int L2;
int ist1;
int iend1;
double tmp;
double u21i;
double u31i;
double u41i;
double u51i;
double u21im1;
double u31im1;
double u41im1;
double u51im1;

void init_vars() {
    for (int i0 = 0; i0 < nx; i0++) {
        for (int j0 = 0; j0 < 65; j0++) {
            for (int k0 = 0; k0 < 65; k0++) {
                for (int m0 = 0; m0 < 5; m0++) {
                    u[i0][j0][k0][m0] = (i0 + j0 + k0 + m0 + 1) * 0.01;
                    rsd[i0][j0][k0][m0] = (i0 + j0 + k0 + m0) * 0.005;
                    flux[i0][j0][k0][m0] = (i0 - j0 + k0 - m0) * 0.002;
                }
            }
        }
    }

    ist = 2;
    iend = nx - 3;
    jst = 1;
    jend = 63;
}