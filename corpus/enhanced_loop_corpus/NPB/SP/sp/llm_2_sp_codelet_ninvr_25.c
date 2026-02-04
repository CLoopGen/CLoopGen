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
    // Variant 1: Memory Access Pattern Modification - Consecutive Access via Pointer Arithmetic
    double (*rhs_ptr)[65][65][65] = rhs;
    int ni = grid_points[0] - 2;
    int nj = grid_points[1] - 2;
    int nk = grid_points[2] - 2;

    for (i = 1; i <= ni; i++) {
        for (j = 1; j <= nj; j++) {
            for (k = 1; k <= nk; k++) {
                // Access elements using pointer arithmetic to promote consecutive memory access
                r1 = (*rhs_ptr)[i][j][k];
                r2 = (*(&rhs_ptr[1]))[i][j][k];
                r3 = (*(&rhs_ptr[2]))[i][j][k];
                r4 = (*(&rhs_ptr[3]))[i][j][k];
                r5 = (*(&rhs_ptr[4]))[i][j][k];

                t1 = bt * r3;
                t2 = 0.5 * (r4 + r5);

                (*rhs_ptr)[i][j][k] = -r2;
                (*(&rhs_ptr[1]))[i][j][k] = r1;
                (*(&rhs_ptr[2]))[i][j][k] = bt * (r4 - r5);
                (*(&rhs_ptr[3]))[i][j][k] = -t1 + t2;
                (*(&rhs_ptr[4]))[i][j][k] = t1 + t2;
            }
        }
    }
}
