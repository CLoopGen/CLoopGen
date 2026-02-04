#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern  double z[14003];
extern  double p[14003];
extern  double q[14003];
extern  double r[14003];
extern int j;



void loop(){
    double alpha = 1.5, beta = 0.8;
    for (j = 1; j <= lastcol - firstcol + 1; j++) {
        q[j] = alpha * p[j] + beta * z[j];
        z[j] = alpha * q[j] - beta * r[j];
        r[j] = alpha * z[j] + beta * p[j];
        p[j] = alpha * r[j] - beta * q[j];
    }
}
