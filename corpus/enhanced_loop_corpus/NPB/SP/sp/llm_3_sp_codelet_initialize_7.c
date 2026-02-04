#include <stdio.h>

extern  double u[5][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // We use a strided access pattern by stepping through the first dimension with a non-unit stride
    // and use pointers to simulate indirect memory access for improved cache behavior in some contexts.
    double (*base)[65][65][65] = u;
    for (i = 0; i <= 64 - 1; i++) {
        for (j = 0; j <= 64 - 1; j++) {
            for (k = 0; k <= 64 - 1; k++) {
                // Access with reverse and strided pattern: [4], [2], [0], then [3], [1]
                base[4][i][j][k] = 1.;
                base[2][i][j][k] = 0.;
                base[0][i][j][k] = 1.;  // Note: 0 and 4 are set to 1
                base[3][i][j][k] = 0.;
                base[1][i][j][k] = 0.;
            }
        }
    }
}
