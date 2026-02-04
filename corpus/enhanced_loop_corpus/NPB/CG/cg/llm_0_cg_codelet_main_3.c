#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern  double z[14003];
extern  double p[14003];
extern  double q[14003];
extern  double r[14003];
extern int j;



void loop(){
for (int k = 1; k <= 2; k++) {
    for (j = 1; j <= lastcol - firstcol + 1; j++) {
        if (k == 1) {
            q[j] = 0.;
            z[j] = 0.;
        } else {
            r[j] = 0.;
            p[j] = 0.;
        }
    }
}
}
