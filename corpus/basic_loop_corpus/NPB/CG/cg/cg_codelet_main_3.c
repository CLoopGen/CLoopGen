#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern  double z[14003];
extern  double p[14003];
extern  double q[14003];
extern  double r[14003];
extern int j;

void loop(){
for (j = 1; j <= lastcol - firstcol + 1; j++) {
    q[j] = 0.;
    z[j] = 0.;
    r[j] = 0.;
    p[j] = 0.;
}

}
