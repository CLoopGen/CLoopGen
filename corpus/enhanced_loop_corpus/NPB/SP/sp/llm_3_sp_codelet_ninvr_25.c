#include <stdio.h>

extern  int grid_points[3];
extern  double bt;
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern double r1;
extern double r2;
extern double r3;
extern double r4;
extern double r5;
extern double t1;
extern double t2;



void loop(){
    // Variant 2: Memory Access Pattern Modification - Strided Access with Fixed Index Offsets
    // Simulate strided access by reordering computation and accessing non-local indices periodically
    // This variant uses a fixed stride of 2 in k-dimension, reading/writing every second element

    int ni = grid_points[0] - 2;
    int nj = grid_points[1] - 2;
    int nk = grid_points[2] - 2;

    for (i = 1; i <= ni; i++) {
        for (j = 1; j <= nj; j++) {
            for (k = 1; k <= nk; k += 2) {  // Stride of 2 in k-direction
                // Base values from current position
                r1 = rhs[0][i][j][k];
                r2 = rhs[1][i][j][k];
                r3 = rhs[2][i][j][k];
                r4 = rhs[3][i][j][k];
                r5 = rhs[4][i][j][k];

                t1 = bt * r3;
                t2 = 0.5 * (r4 + r5);

                rhs[0][i][j][k] = -r2;
                rhs[1][i][j][k] = r1;
                rhs[2][i][j][k] = bt * (r4 - r5);
                rhs[3][i][j][k] = -t1 + t2;
                rhs[4][i][j][k] = t1 + t2;

                // Optional: handle adjacent index if within bounds (maintain coverage)
                if (k + 1 <= nk) {
                    r1 = rhs[0][i][j][k+1];
                    r2 = rhs[1][i][j][k+1];
                    r3 = rhs[2][i][j][k+1];
                    r4 = rhs[3][i][j][k+1];
                    r5 = rhs[4][i][j][k+1];

                    t1 = bt * r3;
                    t2 = 0.5 * (r4 + r5);

                    rhs[0][i][j][k+1] = -r2;
                    rhs[1][i][j][k+1] = r1;
                    rhs[2][i][j][k+1] = bt * (r4 - r5);
                    rhs[3][i][j][k+1] = -t1 + t2;
                    rhs[4][i][j][k+1] = t1 + t2;
                }
            }
        }
    }
}
