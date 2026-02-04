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
        if (j % 2 == 0) {
            q[j] = 0.;
            z[j] = 0.;
        } else {
            q[j] = 1.;
            z[j] = 1.;
        }
        r[j] = x[j];
        p[j] = r[j];
    }
}
