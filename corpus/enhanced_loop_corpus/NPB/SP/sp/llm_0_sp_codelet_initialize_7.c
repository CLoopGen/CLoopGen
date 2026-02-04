#include <stdio.h>

extern  double u[5][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 0; i <= 64 - 1; i++) {
    for (j = 0; j <= 64 - 1; j++) {
        for (k = 0; k <= 64 - 1; k++) {
            for (int n = 0; n <= 4 - 1; n++) {
                if (n == 0 || n == 4) {
                    u[n][i][j][k] = 1.;
                } else {
                    u[n][i][j][k] = 0.;
                }
            }
        }
    }
}
}
