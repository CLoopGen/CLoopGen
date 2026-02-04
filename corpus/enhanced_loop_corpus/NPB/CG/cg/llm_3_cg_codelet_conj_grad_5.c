#include <stdio.h>

extern  int naa;
extern double x[];
extern double z[];
extern double p[];
extern double q[];
extern double r[];
extern int j;



void loop(){
    int *index = &j;
    for (j = 1; j <= naa + 1; j += 2) {
        int idx = *index;
        q[idx] = 0.;
        z[idx] = 0.;
        r[idx] = x[idx];
        p[idx] = r[idx];
        if (idx + 1 <= naa + 1) {
            q[idx + 1] = 0.;
            z[idx + 1] = 0.;
            r[idx + 1] = x[idx + 1];
            p[idx + 1] = r[idx + 1];
        }
    }
}
