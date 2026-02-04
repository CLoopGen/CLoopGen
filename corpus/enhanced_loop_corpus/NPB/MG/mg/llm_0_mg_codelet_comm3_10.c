#include <stdio.h>

extern double ***u;
extern int n1;
extern int n2;
extern int n3;
extern int i1;
extern int i2;



void loop(){
for (i2 = 0; i2 < n2; i2++) {
    u[n3 - 1][i2][0] = u[1][i2][0];
    u[0][i2][0] = u[n3 - 2][i2][0];
    for (i1 = 1; i1 < n1; i1++) {
        u[n3 - 1][i2][i1] = u[1][i2][i1];
        u[0][i2][i1] = u[n3 - 2][i2][i1];
    }
}
}
