#include <stdio.h>
#include <inttypes.h>

int n = 1000;
double A[1300][1300];
double B[1300][1300];
double x[1300];
int i;
int j;

void init_vars() {
    for (int i_init = 0; i_init < 1300; i_init++) {
        for (int j_init = 0; j_init < 1300; j_init++) {
            A[i_init][j_init] = 0.0;
            B[i_init][j_init] = 0.0;
        }
        if (i_init < 1300) {
            x[i_init] = 0.0;
        }
    }
    i = 0;
    j = 0;
}