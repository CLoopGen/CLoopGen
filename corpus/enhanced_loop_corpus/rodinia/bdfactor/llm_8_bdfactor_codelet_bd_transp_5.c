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
    int start_j = (-lbi > 0 ? -lbi : 0);
    int start_p = (l - ub > 0 ? l - ub : 0);
    for (j = l - lb, jj = 0, p = start_j, pp = start_p; j <= n1 && p <= n1; j++, jj++, p++, pp++) {
        in_v[l][pp] = in_v[i][p];
        in_v[i][jj] = in_v[l][j];
    }
    for (; p <= n1; p++, pp++) {
        in_v[l][pp] = in_v[i][p];
    }
}
}
