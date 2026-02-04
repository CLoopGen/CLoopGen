#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern int jj;
extern int l;
extern int lb;
extern int ub;
extern int lub;
extern int n1;
extern double **in_v;
extern int p;
extern int pp;
extern int lbi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (lub + 1) / 2; i++) {
    l = lub - i;
    lbi = lb - i;
    for (j = l - lb, jj = 0, p = ((-lbi) > (0) ? (-lbi) : (0)), pp = ((l - ub) > (0) ? (l - ub) : (0)); j <= n1; j++, jj++, p++, pp++) {
        in_v[l][pp] = in_v[i][p];
        in_v[i][jj] = in_v[l][j];
    }
    for (; p <= n1 - ((lbi) > (0) ? (lbi) : (0)); p++, pp++)
        in_v[l][pp] = in_v[i][p];
}
}
