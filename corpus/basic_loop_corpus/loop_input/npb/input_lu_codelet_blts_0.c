#include <stdio.h>

int k = 1;
double omega = 0.5;
double v[64][65][65][5];
double ldz[64][64][5][5];
int ist = 0;
int iend = 63;
int jst = 0;
int jend = 63;
int i = 0;
int j = 0;
int m = 0;

void init_vars() {
    for (int i_idx = 0; i_idx < 64; i_idx++) {
        for (int j_idx = 0; j_idx < 64; j_idx++) {
            for (int kp = 0; kp < 65; kp++) {
                for (int m_idx = 0; m_idx < 5; m_idx++) {
                    if (kp == k) {
                        v[i_idx][j_idx][kp][m_idx] = (double)(i_idx + j_idx + kp + m_idx) * 0.1;
                    } else if (kp == k - 1) {
                        v[i_idx][j_idx][kp][m_idx] = (double)(i_idx + j_idx + kp + m_idx) * 0.2;
                    }
                }
            }
            for (int m1 = 0; m1 < 5; m1++) {
                for (int m2 = 0; m2 < 5; m2++) {
                    ldz[i_idx][j_idx][m1][m2] = (double)(m1 * m2 + 1) * 0.01;
                }
            }
        }
    }
    ist = 0;
    iend = 63;
    jst = 0;
    jend = 63;
    k = 1;
    omega = 0.5;
}