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
for (i = 0 , l = lub; i < (lub + 1) / 2; i++ , l--) {
    lbi = lb - i;
    int start_j = l - lb;
    int end_j = n1;
    int p_val = (-lbi > 0) ? -lbi : 0;
    int pp_val = (l - ub > 0) ? l - ub : 0;
    for (j = start_j, jj = 0; j <= end_j; j++, jj++, p_val++, pp_val++) {
        if (p_val <= n1) {
            in_v[l][pp_val] = in_v[i][p_val];
        }
        if (jj <= n1) {
            in_v[i][jj] = in_v[l][j];
        }
    }
    for (; p_val <= n1 - ((lbi > 0) ? lbi : 0); p_val++, pp_val++) {
        in_v[l][pp_val] = in_v[i][p_val];
    }
}
}
