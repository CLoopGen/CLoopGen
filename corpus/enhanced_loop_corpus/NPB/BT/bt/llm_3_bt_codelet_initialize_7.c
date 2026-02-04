#include <stdio.h>

extern  double u[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 2: Strided memory access — access every second element in the k-dimension, stepping by 2
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 64; j++) {
            for (k = 0; k < 64; k += 2) {  // Stride of 2 in k-loop
                for (m = 0; m < 5; m++) {
                    u[i][j][k][m] = 1.;
                }
            }
        }
    }
}
