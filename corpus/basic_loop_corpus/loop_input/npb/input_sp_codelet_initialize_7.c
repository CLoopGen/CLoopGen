#include <stdio.h>

double u[5][65][65][65];
int i;
int j;
int k;

void init_vars() {
    for (int idx_i = 0; idx_i <= 64 - 1; idx_i++) {
        for (int idx_j = 0; idx_j <= 64 - 1; idx_j++) {
            for (int idx_k = 0; idx_k <= 64 - 1; idx_k++) {
                u[0][idx_i][idx_j][idx_k] = 0.0;
                u[1][idx_i][idx_j][idx_k] = 0.0;
                u[2][idx_i][idx_j][idx_k] = 0.0;
                u[3][idx_i][idx_j][idx_k] = 0.0;
                u[4][idx_i][idx_j][idx_k] = 0.0;
            }
        }
    }
}