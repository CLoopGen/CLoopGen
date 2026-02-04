#include <stdio.h>

int nz = 64;
int ist = 1;
int iend = 63;
int jst = 1;
int jend = 63;
double tz1 = 1.0;
double tz2 = 1.5;
double tz3 = 2.0;
double dz1 = 0.1;
double dz2 = 0.15;
double dz3 = 0.2;
double dz4 = 0.25;
double dz5 = 0.3;
double dssp = 0.05;

double u[64][65][65][5];
double rsd[64][65][65][5];
double flux[64][65][65][5];

int i;
int j;
int k;
int m;
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
    for (int i_idx = 0; i_idx < 64; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int m_idx = 0; m_idx < 5; m_idx++) {
                    u[i_idx][j_idx][k_idx][m_idx] = (i_idx + j_idx + k_idx + m_idx) * 0.1;
                    rsd[i_idx][j_idx][k_idx][m_idx] = (i_idx + j_idx + k_idx + m_idx) * 0.01;
                    flux[i_idx][j_idx][k_idx][m_idx] = (i_idx + j_idx + k_idx + m_idx) * 0.05;
                }
            }
        }
    }

    i = 0;
    j = 0;
    k = 0;
    m = 0;
    q = 0.0;
    u41 = 0.0;
    tmp = 0.0;
    u21k = 0.0;
    u31k = 0.0;
    u41k = 0.0;
    u51k = 0.0;
    u21km1 = 0.0;
    u31km1 = 0.0;
    u41km1 = 0.0;
    u51km1 = 0.0;
}