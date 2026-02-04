#include <stdio.h>

extern double ***u;
extern int n1;
extern int n2;
extern int n3;
extern int i1;
extern int i2;



void loop(){
    for (i2 = 0; i2 < n2; i2++) {
        for (i1 = 0; i1 < n1; i1++) {
            if ((i1 + i2) % 2 == 0) {
                u[n3 - 1][i2][i1] = u[1][i2][i1];
            }
            if ((i1 + i2) % 2 == 1) {
                u[0][i2][i1] = u[n3 - 2][i2][i1];
            }
        }
    }
}
