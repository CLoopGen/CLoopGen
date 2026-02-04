#include <stdio.h>
#include <inttypes.h>

int nx = 900;
int ny = 1100;
double ex[1000][1200];
double ey[1000][1200];
double hz[1000][1200];
int i;
int j;

void init_vars() {
    for (int i_init = 0; i_init < 1000; i_init++) {
        for (int j_init = 0; j_init < 1200; j_init++) {
            ex[i_init][j_init] = 0.0;
            ey[i_init][j_init] = 0.0;
            hz[i_init][j_init] = 0.0;
        }
    }
    nx = 900;
    ny = 1100;
}