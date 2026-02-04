#include <stdio.h>

extern  int naa;
extern double x[];
extern double z[];
extern double p[];
extern double q[];
extern double r[];
extern int j;



void loop(){
    int j;
    for (j = 1; j <= naa + 1; j++) {
        {
            q[j] = 0.;
            z[j] = 0.;
            r[j] = x[j];
            p[j] = r[j];
        }
    }
}
