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
    int stride = 2; // Access every second element
    for (j = l - lb , jj = 0 , p = ((-lbi) > (0) ? (-lbi) : (0)) , pp = ((l - ub) > (0) ? (l - ub) : (0)); j <= n1; j += stride, jj += stride, p += stride, pp += stride) {
        if (j + stride - 1 <= n1) { // Ensure bounds
            in_v[l][pp] = in_v[i][p];
            in_v[i][jj] = in_v[l][j];
        }
    }
    for (; p <= n1 - ((lbi) > (0) ? (lbi) : (0)); p += stride, pp += stride)
        in_v[l][pp] = in_v[i][p];
}
}
