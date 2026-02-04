#include <stdio.h>

int grid_points[3];
double comz1;
double comz4;
double comz5;
double comz6;
double lhs[15][65][65][65];
int i;
int j;
int k;

void init_vars() {
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;
    
    comz1 = 1.0;
    comz4 = 2.0;
    comz5 = 3.0;
    comz6 = 4.0;
    
    j = 32;
    
    for (int idx = 0; idx < 15; idx++) {
        for (int i_idx = 0; i_idx < 65; i_idx++) {
            for (int j_idx = 0; j_idx < 65; j_idx++) {
                for (int k_idx = 0; k_idx < 65; k_idx++) {
                    lhs[idx][i_idx][j_idx][k_idx] = (double)(idx + i_idx + j_idx + k_idx);
                }
            }
        }
    }
}