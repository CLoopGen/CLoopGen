#include <stdio.h>

extern  int naa;
extern double x[];
extern double z[];
extern double p[];
extern double q[];
extern double r[];
extern int j;



void loop(){
    double temp_q, temp_z;
    for (j = 1; j <= naa + 1; j++) {
        temp_q = 0.;
        temp_z = 0.;
        q[j] = temp_q;
        z[j] = temp_z;
        r[j] = x[j];
        p[j] = r[j];
    }
}
