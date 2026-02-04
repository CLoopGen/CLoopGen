#include <stdio.h>

int ny = 64;
int nz = 65;
int ist = 1;
int iend = 32;
int jst = 2;
int jend = 62;
double ty1 = 0.1;
double ty2 = 0.15;
double ty3 = 0.2;
double dy1 = 0.05;
double dy2 = 0.06;
double dy3 = 0.07;
double dy4 = 0.08;
double dy5 = 0.09;
double dssp = 0.01;
double u[64][65][65][5];
double rsd[64][65][65][5];
double flux[64][65][65][5];
int i;
int j;
int k;
int m;
int L2;
int jst1;
int jend1;
double tmp;
double u21j;
double u31j;
double u41j;
double u51j;
double u21jm1;
double u31jm1;
double u41jm1;
double u51jm1;

void init_vars() {
    for (int i_idx = 0; i_idx < 64; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int m_idx = 0; m_idx < 5; m_idx++) {
                    u[i_idx][j_idx][k_idx][m_idx] = (double)(i_idx + j_idx + k_idx + m_idx + 1) * 0.01;
                    rsd[i_idx][j_idx][k_idx][m_idx] = (double)(i_idx + j_idx + k_idx + m_idx + 2) * 0.02;
                    flux[i_idx][j_idx][k_idx][m_idx] = (double)(i_idx + j_idx + k_idx + m_idx + 3) * 0.03;
                }
            }
        }
    }

    ty1 = 0.1;
    ty2 = 0.15;
    ty3 = 0.2;
    dy1 = 0.05;
    dy2 = 0.06;
    dy3 = 0.07;
    dy4 = 0.08;
    dy5 = 0.09;
    dssp = 0.01;

    ny = 64;
    nz = 65;
    ist = 1;
    iend = 32;
    jst = 2;
    jend = 62;

    i = j = k = m = 0;
    L2 = jst;
    jst1 = 3;
    jend1 = ny - 4;

    tmp = 1.0;
    u21j = u31j = u41j = u51j = 0.0;
    u21jm1 = u31jm1 = u41jm1 = u51jm1 = 0.0;
}