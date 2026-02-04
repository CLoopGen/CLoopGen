#include <stdio.h>

extern  int naa;
extern double x[];
extern double z[];
extern double p[];
extern double q[];
extern double r[];
extern int j;



void loop(){
    int i;
    for (i = 1; i <= naa + 1; i++) {
        q[i] = 0.;
        z[i] = 0.;
        r[i] = x[i];
        p[i] = r[i];
    }
}
