#include <stdio.h>

int grid_points[3];
double forcing[65][65][65][6];
int m;
int i;
int j;
int k;

void init_vars() {
    // Set grid dimensions to ensure total data size is about 1.7 MB
    // forcing array has dimensions [65][65][65][6] -> fixed at compile time
    // Each double is 8 bytes -> total size = 65*65*65*6*8 = 13,183,800 bytes (~13MB)
    // We'll use full array to get measurable runtime (target ~0.01 sec)
    
    grid_points[0] = 65;
    grid_points[1] = 65;
    grid_points[2] = 65;
    
    // Initialize the forcing array to zero outside of loop context
    // The loop will overwrite this, but we initialize for correctness
    for (int i_idx = 0; i_idx < 65; i_idx++) {
        for (int j_idx = 0; j_idx < 65; j_idx++) {
            for (int k_idx = 0; k_idx < 65; k_idx++) {
                for (int m_idx = 0; m_idx < 6; m_idx++) {
                    forcing[i_idx][j_idx][k_idx][m_idx] = 1.0; // non-zero initial value
                }
            }
        }
    }
    
    // Initialize loop indices to safe values
    i = 0;
    j = 0;
    k = 0;
    m = 0;
}