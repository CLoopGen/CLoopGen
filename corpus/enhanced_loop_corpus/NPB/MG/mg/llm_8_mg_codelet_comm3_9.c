#include <stdio.h>

extern double ***u;
extern int n1;
extern int n2;
extern int n3;
extern int i1;
extern int i2;
extern int i3;



void loop(){
for (i3 = 1; i3 < n3 - 1; i3++) {
    for (i2 = 1; i2 < n2 - 1; i2++) {
        u[i3][i2][n1 - 1] = (u[i3][i2][1] + u[i3][i2][2]) * 0.5;
        u[i3][i2][0] = (u[i3][i2][n1 - 2] + u[i3][i2][n1 - 3]) * 0.5;
    }
    for (i1 = 0; i1 < n1; i1++) {
        u[i3][n2 - 1][i1] = (u[i3][1][i1] + u[i3][2][i1]) * 0.5;
        u[i3][0][i1] = (u[i3][n2 - 2][i1] + u[i3][n2 - 3][i1]) * 0.5;
    }
}
}
