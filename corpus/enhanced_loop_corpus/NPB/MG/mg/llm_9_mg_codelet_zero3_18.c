#include <stdio.h>

extern double ***z;
extern int n1;
extern int n2;
extern int n3;
extern int i1;
extern int i2;
extern int i3;



void loop(){
    for (i3 = 0; i3 < n3; i3 += 2) {
        for (i2 = 0; i2 < n2; i2 += 2) {
            for (i1 = 0; i1 < n1; i1 += 2) {
                z[i3][i2][i1] = 0.;
                if (i3 + 1 < n3) z[i3+1][i2][i1] = 0.;
                if (i2 + 1 < n2) z[i3][i2+1][i1] = 0.;
                if (i1 + 1 < n1) z[i3][i2][i1+1] = 0.;
            }
        }
    }
}
