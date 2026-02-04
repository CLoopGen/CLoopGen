#include <stdio.h>
#include <inttypes.h>

int n = 1500;
int path[2800][2800];
int i;
int j;

void init_vars() {
    for (int i_init = 0; i_init < 2800; i_init++) {
        for (int j_init = 0; j_init < 2800; j_init++) {
            path[i_init][j_init] = 0;
        }
    }
    n = 1500;
    i = 0;
    j = 0;
}