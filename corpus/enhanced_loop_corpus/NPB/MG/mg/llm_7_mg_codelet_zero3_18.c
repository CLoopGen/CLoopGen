#include <stdio.h>

extern double ***z;
extern int n1;
extern int n2;
extern int n3;
extern int i1;
extern int i2;
extern int i3;



void loop(){
    double temp = 0.0;
    for (i3 = 0; i3 < n3; i3++) {
        for (i2 = 0; i2 < n2; i2++) {
            temp = 0.0;
            for (i1 = 0; i1 < n1; i1++) {
                temp += (i1 + 1) * 0.1;
                z[i3][i2][i1] = temp;
            }
        }
    }
}
