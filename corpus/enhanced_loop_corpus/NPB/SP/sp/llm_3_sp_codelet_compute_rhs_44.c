#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[5][65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 2: Memory Access Pattern Modification - Strided Access Simulation using Pointer Arithmetic
    // We simulate strided memory access by precomputing base pointers for each [m][i][j] slice
    // and then applying offsets manually. This exposes memory access pattern more explicitly
    // and could be optimized differently by compiler or target architecture.

    for (m = 0; m < 5; m++) {
        for (i = 1; i <= grid_points[0] - 2; i++) {
            for (j = 1; j <= grid_points[1] - 2; j++) {
                double * restrict rhs_ptr = &rhs[m][i][j][k];
                double * restrict u_base = &u[m][i][j][k - 2];

                // Access with fixed offset from base pointer (strided pattern over k-dimension)
                *rhs_ptr = *rhs_ptr - dssp * (u_base[0] - 4. * u_base[1] + 6. * u_base[2] - 4. * u_base[3]);
            }
        }
    }
}
