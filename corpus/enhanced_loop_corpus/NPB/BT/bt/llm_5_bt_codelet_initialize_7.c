#include <stdio.h>

extern  double u[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 64; j++) {
            for (k = 0; k < 64; k++) {
                for (m = 0; m < 5; m++) {
                    if (m >= 1 && m <= 3) {
                        u[i][j][k][m] = 1.;
                    } else {
                        u[i][j][k][m] = 0.;
                    }
                }
            }
        }
    }
}
