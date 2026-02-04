#include <stdio.h>

extern  double u[5][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
    // Variant 1: Consecutive memory access by reordering the array dimensions access
    // We transpose the access pattern to improve spatial locality assuming row-major order.
    // Instead of iterating u[0..4][i][j][k], we fix i,j,k and iterate over the first dimension consecutively.
    for (i = 0; i <= 64 - 1; i++) {
        for (j = 0; j <= 64 - 1; j++) {
            for (k = 0; k <= 64 - 1; k++) {
                int idx;
                for (idx = 0; idx < 5; idx++) {
                    if (idx == 0 || idx == 4) {
                        u[idx][i][j][k] = 1.;
                    } else {
                        u[idx][i][j][k] = 0.;
                    }
                }
            }
        }
    }
}
