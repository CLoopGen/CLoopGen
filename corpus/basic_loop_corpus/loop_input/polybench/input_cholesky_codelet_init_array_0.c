#include <stdio.h>
#include <inttypes.h>

int n = 1500;
double A[2000][2000];
int i;
int j;

void init_vars() {
    for (int i_init = 0; i_init < 2000; i_init++) {
        for (int j_init = 0; j_init < 2000; j_init++) {
            A[i_init][j_init] = 0.0;
        }
    }
    n = 1500;
}