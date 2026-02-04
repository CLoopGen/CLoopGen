#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 2: Modify access pattern using indirect indexing via a fixed index map
    // Simulates irregular access pattern, though data is still accessed fully
    const int index_map[5] = {0, 1, 2, 3, 4}; // Identity map for clarity, could be reordered in real use cases
    for (i = 0; i < grid_points[0]; i++) {
        for (j = 0; j < grid_points[1]; j++) {
            for (k = 0; k < grid_points[2]; k++) {
                for (m = 0; m < 5; m++) {
                    int idx = index_map[m]; // Indirect access through mapping
                    rhs[i][j][k][idx] = forcing[i][j][k][idx];
                }
            }
        }
    }
}
