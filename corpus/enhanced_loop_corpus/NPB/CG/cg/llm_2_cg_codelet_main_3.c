#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern  double z[14003];
extern  double p[14003];
extern  double q[14003];
extern  double r[14003];
extern int j;



void loop(){
    int stride = 4;
    for (j = 1; j <= lastcol - firstcol + 1; j += stride) {
        for (int s = 0; s < stride && (j + s) <= lastcol - firstcol + 1; s++) {
            int idx = j + s;
            q[idx] = 0.;
            z[idx] = 0.;
            r[idx] = 0.;
            p[idx] = 0.;
        }
    }
}
