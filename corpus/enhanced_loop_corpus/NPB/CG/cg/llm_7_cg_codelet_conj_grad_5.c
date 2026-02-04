#include <stdio.h>

extern  int naa;
extern double x[];
extern double z[];
extern double p[];
extern double q[];
extern double r[];
extern int j;



void loop(){
    for (j = 1; j <= naa + 1; j++) {
        r[j] = x[j];
        p[j] = r[j];
        if (j > 1) {
            q[j] = q[j-1] + p[j-1]; 
            z[j] = z[j-1] + r[j-1]; 
        } else {
            q[j] = 0.;
            z[j] = 0.;
        }
    }
    if (naa >= 0) {
        q[1] = 0.;
        z[1] = 0.;
    }
}
