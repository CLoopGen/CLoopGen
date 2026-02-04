#include <stdio.h>

int nz0 = 64;
int ist = 0;
int iend = 63;
int jst = 0;
int jend = 64;
double v[64][65][65][5];
int i;
int j;
int k;
double sum0 = 0.0;
double sum1 = 0.0;
double sum2 = 0.0;
double sum3 = 0.0;
double sum4 = 0.0;

void init_vars() {
    for (int idx_i = 0; idx_i < 64; idx_i++) {
        for (int idx_j = 0; idx_j < 65; idx_j++) {
            for (int idx_k = 0; idx_k < 65; idx_k++) {
                for (int idx_n = 0; idx_n < 5; idx_n++) {
                    v[idx_i][idx_j][idx_k][idx_n] = (double)(idx_i + idx_j + idx_k + idx_n) * 0.1;
                }
            }
        }
    }
}