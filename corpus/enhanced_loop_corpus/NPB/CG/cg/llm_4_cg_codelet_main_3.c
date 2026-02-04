#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern  double z[14003];
extern  double p[14003];
extern  double q[14003];
extern  double r[14003];
extern int j;



void loop(){
    int start = firstcol;
    int end = lastcol;
    int len = end - start + 1;

    for (j = 1; j <= len; j++) {
        if (j <= len) {
            q[j] = 0.;
            z[j] = 0.;
            r[j] = 0.;
            p[j] = 0.;
        }
    }
}
