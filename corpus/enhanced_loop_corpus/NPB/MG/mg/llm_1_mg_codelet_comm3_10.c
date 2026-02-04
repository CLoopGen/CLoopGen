#include <stdio.h>

extern double ***u;
extern int n1;
extern int n2;
extern int n3;
extern int i1;
extern int i2;



void loop(){
for (i2 = 0; i2 < n2; i2++) {
    for (int j = 0; j < n1; j += 2) {
        if (j + 1 < n1) {
            u[n3 - 1][i2][j]     = u[1][i2][j];
            u[0][i2][j]         = u[n3 - 2][i2][j];
            u[n3 - 1][i2][j + 1] = u[1][i2][j + 1];
            u[0][i2][j + 1]     = u[n3 - 2][i2][j + 1];
        } else {
            u[n3 - 1][i2][j] = u[1][i2][j];
            u[0][i2][j]     = u[n3 - 2][i2][j];
        }
    }
}
}
