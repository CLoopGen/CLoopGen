#include <stdio.h>

int ny = 64;
int nz = 65;
int ist = 1;
int iend = 63;
int jst = 2;
int jend = 62;
int L2 = 62;
int jst1;
int jend1;

double ty1 = 0.1;
double ty2 = 0.2;
double ty3 = 0.3;
double dy1 = 0.05;
double dy2 = 0.06;
double dy3 = 0.07;
double dy4 = 0.08;
double dy5 = 0.09;
double dsspm = 0.01;
double tmp;
double u21j;
double u31j;
double u41j;
double u51j;
double u21jm1;
double u31jm1;
double u41jm1;
double u51jm1;

double rsd[64][65][65][5];
double frct[64][65][65][5];
double flux[64][65][65][5];

int i, j, k, m;

void init_vars() {
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 65; j++) {
            for (k = 0; k < 65; k++) {
                for (m = 0; m < 5; m++) {
                    rsd[i][j][k][m] = (double)(i + j + k + m + 1) * 0.01;
                    frct[i][j][k][m] = (double)(i + j + k + m) * 0.02;
                    flux[i][j][k][m] = (double)(i + j + k + m) * 0.03;
                }
            }
        }
    }

    ny = 64;
    nz = 65;
    ist = 1;
    iend = 62;
    jst = 2;
    jend = 61;
    L2 = 61;
}