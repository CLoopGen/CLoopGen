#include <stdio.h>
#include <inttypes.h>

typedef char base;

int n = 1500;
base seq[2500];
int table[2500][2500];
int i;
int j;
int k;

void init_vars() {
    for (int idx = 0; idx < 2500; idx++) {
        seq[idx] = (base)(idx % 4); // values 0,1,2,3 cycling
    }
    
    for (int i_idx = 0; i_idx < 2500; i_idx++) {
        for (int j_idx = 0; j_idx < 2500; j_idx++) {
            table[i_idx][j_idx] = (i_idx <= j_idx) ? ((i_idx + j_idx) % 10) : 0;
        }
    }
    
    i = 0;
    j = 0;
    k = 0;
}