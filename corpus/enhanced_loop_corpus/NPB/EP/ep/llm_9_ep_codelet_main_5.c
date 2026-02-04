#include <stdio.h>

extern  double q[10];
extern int i;
extern double qq[10];



void loop(){
    double temp1, temp2;
    for (i = 0; i <= 10 - 1; i++) {
        temp1 = qq[i] * 1.5;
        temp2 = temp1 + 2.5;
        q[i] = q[i] + temp2 - 1.5;
    }
}
