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
for (i = 0; i < (lub + 1); i += 3) {
    l = lub - i;
    if (l < 0) break;
    lbi = lb - i;
    int lower_bound_p = (-lbi > 0 ? -lbi : 0);
    int upper_bound_p = n1 - ((lbi > 0) ? lbi : 0);
    for (int k = 0; k < 4; k++) {
        for (p = lower_bound_p; p <= upper_bound_p; p++) {
            if (i < (lub + 1)/2 && l >= 0) {
                int j = l - lb + p - lower_bound_p;
                int jj = p - lower_bound_p;
                int pp = (l - ub > 0 ? l - ub : 0) + jj;
                if (j <= n1 && jj >= 0 && pp >= 0) {
                    in_v[l][pp] = in_v[i][p];
                    in_v[i][jj] = in_v[l][j];
                }
            }
        }
    }
}
}
