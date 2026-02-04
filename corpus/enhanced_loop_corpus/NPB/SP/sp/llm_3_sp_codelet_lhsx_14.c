#include <stdio.h>

extern  int grid_points[3];
extern  double dttx2;
extern  double speed[65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Modify access pattern to use strided access across lhs first dimension with non-unit stride emulation via indexing array
    // Simulate irregular but predictable access using a fixed offset map (stride-like behavior)
    const int offsets[10] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                double speed_im1 = speed[i - 1][j][k];
                double speed_ip1 = speed[i + 1][j][k];
                
                // Strided write pattern: alternate between different lhs layers using pre-defined offset list
                for (int idx = 0; idx < 10; idx++) {
                    int n = offsets[idx];
                    if (n == 5 || n == 10) {
                        lhs[n][i][j][k] = lhs[0][i][j][k];
                    } else if (n == 6) {
                        lhs[n][i][j][k] = lhs[1][i][j][k] - dttx2 * speed_im1;
                    } else if (n == 11) {
                        lhs[n][i][j][k] = lhs[1][i][j][k] + dttx2 * speed_im1;
                    } else if (n == 8) {
                        lhs[n][i][j][k] = lhs[3][i][j][k] + dttx2 * speed_ip1;
                    } else if (n == 13) {
                        lhs[n][i][j][k] = lhs[3][i][j][k] - dttx2 * speed_ip1;
                    } else {
                        // Handle even indices: map 7,9,12,14 -> 2,4
                        int src_idx = (n % 2 == 0) ? 4 : 2;
                        lhs[n][i][j][k] = lhs[src_idx][i][j][k];
                    }
                }
            }
        }
    }
}
