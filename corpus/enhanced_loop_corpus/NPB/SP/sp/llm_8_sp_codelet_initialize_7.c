#include <stdio.h>

extern  double u[5][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 0; i <= 64 - 1; i++) {
    for (j = 0; j <= 64 - 1; j++) {
        for (k = 0; k <= 64 - 1; k += 2) { // Reduced trip count by unrolling and skipping every other element
            u[0][i][j][k] = 1.;
            u[1][i][j][k] = 0.;
            u[2][i][j][k] = 0.;
            u[3][i][j][k] = 0.;
            u[4][i][j][k] = 1.;
            if (k + 1 < 64) { // Handle remaining element in pair if within bounds
                u[0][i][j][k+1] = 1.;
                u[1][i][j][k+1] = 0.;
                u[2][i][j][k+1] = 0.;
                u[3][i][j][k+1] = 0.;
                u[4][i][j][k+1] = 1.;
            }
        }
    }
}
}
