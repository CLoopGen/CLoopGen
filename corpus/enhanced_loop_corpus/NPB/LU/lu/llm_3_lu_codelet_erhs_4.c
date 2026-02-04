#include <stdio.h>

extern  int nx;
extern  int ny;
extern  int nz;
extern  double frct[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 2: Reverse the loop order to access memory in reverse consecutive order (cache-friendly in some contexts)
    for (i = nx - 1; i >= 0; i--) {
        for (j = ny - 1; j >= 0; j--) {
            for (k = nz - 1; k >= 0; k--) {
                for (m = 4; m >= 0; m--) {
                    frct[i][j][k][m] = 0.;
                }
            }
        }
    }
}
