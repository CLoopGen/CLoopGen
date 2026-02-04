#include <stdio.h>

int nx = 64;
int nz = 65;
int ist = 2;
int iend = 61;
int jst = 1;
int jend = 63;
int L2 = 61;
int ist1;
int iend1;
double tx1 = 0.1;
double tx2 = 0.2;
double tx3 = 0.3;
double dx1 = 0.05;
double dx2 = 0.06;
double dx3 = 0.07;
double dx4 = 0.08;
double dx5 = 0.09;
double dsspm = 0.01;
double tmp;
double u21i;
double u31i;
double u41i;
double u51i;
double u21im1;
double u31im1;
double u41im1;
double u51im1;

double rsd[64][65][65][5];
double frct[64][65][65][5];
double flux[64][65][65][5];

int i, j, k, m;

void init_vars() {
    for (int idx_i = 0; idx_i < 64; idx_i++) {
        for (int idx_j = 0; idx_j < 65; idx_j++) {
            for (int idx_k = 0; idx_k < 65; idx_k++) {
                for (int idx_m = 0; idx_m < 5; idx_m++) {
                    rsd[idx_i][idx_j][idx_k][idx_m] = (double)(idx_i + idx_j + idx_k + idx_m + 1) * 0.01;
                    frct[idx_i][idx_j][idx_k][idx_m] = (double)(idx_i + idx_j + idx_k + idx_m + 1) * 0.02;
                    flux[idx_i][idx_j][idx_k][idx_m] = (double)(idx_i + idx_j + idx_k + idx_m + 1) * 0.03;
                }
            }
        }
    }

    nx = 64;
    nz = 65;
    ist = 2;
    iend = nx - 3;
    jst = 1;
    jend = nz - 2;
    L2 = iend;

    tx1 = 0.1;
    tx2 = 0.2;
    tx3 = 0.3;
    dx1 = 0.05;
    dx2 = 0.06;
    dx3 = 0.07;
    dx4 = 0.08;
    dx5 = 0.09;
    dsspm = 0.01;

    ist1 = 3;
    iend1 = nx - 4;
}