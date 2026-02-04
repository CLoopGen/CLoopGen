#include <stdio.h>
#include <inttypes.h>

int n = 100;

double A[120][120][120];
double B[120][120][120];

int i = 0;
int j = 0;
int k = 0;

void init_vars() {
    for (int i_init = 0; i_init < 120; i_init++) {
        for (int j_init = 0; j_init < 120; j_init++) {
            for (int k_init = 0; k_init < 120; k_init++) {
                A[i_init][j_init][k_init] = 0.0;
                B[i_init][j_init][k_init] = 0.0;
            }
        }
    }
}