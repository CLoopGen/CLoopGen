#include <stdio.h>

int nz = 64;
int jst = 0;
int jend = 63;
double rsd[64][65][65][5];
double flux[64][65][65][5];
int i;
int j;
int k;
int L1 = 0;
int L2 = 63;

double q;
double u21;

void init_vars() {
    for (int i_idx = 0; i_idx < 64; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int m_idx = 0; m_idx < 5; m_idx++) {
                    rsd[i_idx][j_idx][k_idx][m_idx] = (double)(i_idx + j_idx + k_idx + m_idx + 1) * 0.01;
                    flux[i_idx][j_idx][k_idx][m_idx] = 0.0;
                }
            }
        }
    }
    q = 0.0;
    u21 = 0.0;
}