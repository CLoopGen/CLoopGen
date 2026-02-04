#include <stdio.h>

int nz = 64;
int jst = 0;
int jend = 63;
double u[64][65][65][5];
double flux[64][65][65][5];
int i;
int j;
int k;
int L1 = 0;
int L2 = 63;

double q;
double u21;

void init_vars() {
    for (int idx_i = 0; idx_i < 64; idx_i++) {
        for (int idx_j = 0; idx_j < 65; idx_j++) {
            for (int idx_k = 0; idx_k < 65; idx_k++) {
                double rho = 1.0 + 0.1 * idx_i;
                double u1 = 0.1 * idx_j;
                double u2 = 0.1 * idx_k;
                double u3 = 0.05 * (idx_j + idx_k);
                double e = 2.5 + 0.2 * idx_i;
                
                u[idx_i][idx_j][idx_k][0] = rho;
                u[idx_i][idx_j][idx_k][1] = rho * u1;
                u[idx_i][idx_j][idx_k][2] = rho * u2;
                u[idx_i][idx_j][idx_k][3] = rho * u3;
                u[idx_i][idx_j][idx_k][4] = rho * e + 0.5 * rho * (u1*u1 + u2*u2 + u3*u3);
                
                for (int n = 0; n < 5; n++) {
                    flux[idx_i][idx_j][idx_k][n] = 0.0;
                }
            }
        }
    }
    
    i = 0;
    j = 0;
    k = 0;
    q = 0.0;
    u21 = 0.0;
}