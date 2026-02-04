#include <stdio.h>

int grid_points[3] = {64, 64, 64};

double rhs[5][65][65][65];
double lhs[15][65][65][65];

int i;
int j;
int k;
int n;
int k1;
int k2;
int m;

void init_vars() {
    for (int m_idx = 0; m_idx < 5; m_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    rhs[m_idx][i_idx][j_idx][k_idx] = (double)(m_idx + 1) * 0.01;
                }
            }
        }
    }

    for (int l_idx = 0; l_idx < 15; l_idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    lhs[l_idx][i_idx][j_idx][k_idx] = (double)(l_idx + 1) * 0.02;
                }
            }
        }
    }

    i = 0;
    j = 0;
    k = 0;
    n = 0;
    k1 = 0;
    k2 = 0;
    m = 0;
}