#include <stdio.h>

extern  double q[10];
extern int i;
extern double qq[10];



void loop(){
    double temp[10];
    for (i = 0; i <= 10 - 1; i++) {
        temp[i] = qq[i];
        q[i] += temp[i];
    }
}
