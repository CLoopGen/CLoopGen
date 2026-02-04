#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern  double z[14003];
extern  double p[14003];
extern  double q[14003];
extern  double r[14003];
extern int j;



void loop(){
    double temp_q, temp_z, temp_r, temp_p;
    temp_q = 0.;
    temp_z = 0.;
    temp_r = 0.;
    temp_p = 0.;
    for (j = 1; j <= lastcol - firstcol + 1; j++) {
        temp_q = temp_p;
        temp_z = temp_q;
        temp_r = temp_z;
        temp_p = temp_r;

        q[j] = temp_q;
        z[j] = temp_z;
        r[j] = temp_r;
        p[j] = temp_p;
    }
}
