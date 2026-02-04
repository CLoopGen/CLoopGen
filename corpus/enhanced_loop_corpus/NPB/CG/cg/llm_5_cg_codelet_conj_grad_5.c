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
        q[j] = 0.;
        z[j] = 0.;
        r[j] = x[j];
        if (r[j] > 0.0) {
            p[j] = r[j];
        } else {
            p[j] = 0.0;
        }
    }
}
