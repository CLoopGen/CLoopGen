#include <stdio.h>

extern double ***u;
extern int n1;
extern int n2;
extern int n3;
extern int i1;
extern int i2;
extern int i3;



void loop(){
for (i3 = 2; i3 < n3 - 2; i3 += 2) {
    for (i2 = 2; i2 < n2 - 2; i2 += 2) {
        u[i3][i2][n1 - 1] = u[i3][i2][1];
        u[i3][i2][0] = u[i3][i2][n1 - 2];
        if (i3 + 1 < n3 - 1) {
            u[i3+1][i2][n1 - 1] = u[i3+1][i2][1];
            u[i3+1][i2][0] = u[i3+1][i2][n1 - 2];
        }
        if (i2 + 1 < n2 - 1) {
            u[i3][i2+1][n1 - 1] = u[i3][i2+1][1];
            u[i3][i2+1][0] = u[i3][i2+1][n1 - 2];
        }
    }
    for (i1 = 0; i1 < n1; i1++) {
        u[i3][n2 - 1][i1] = u[i3][1][i1];
        u[i3][0][i1] = u[i3][n2 - 2][i1];
        if (i3 + 1 < n3 - 1) {
            u[i3+1][n2 - 1][i1] = u[i3+1][1][i1];
            u[i3+1][0][i1] = u[i3+1][n2 - 2][i1];
        }
    }
}
}
