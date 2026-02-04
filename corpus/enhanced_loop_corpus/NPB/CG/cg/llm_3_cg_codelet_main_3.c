#include <stdio.h>

extern  int firstcol;
extern  int lastcol;
extern  double z[14003];
extern  double p[14003];
extern  double q[14003];
extern  double r[14003];
extern int j;



void loop(){
    int indices[14003];
    int n = lastcol - firstcol + 1;
    for (int i = 1; i <= n; i++) {
        indices[i] = i;
    }
    for (j = 1; j <= n; j++) {
        int idx = indices[j];
        q[idx] = 0.;
        z[idx] = 0.;
        r[idx] = 0.;
        p[idx] = 0.;
    }
}
