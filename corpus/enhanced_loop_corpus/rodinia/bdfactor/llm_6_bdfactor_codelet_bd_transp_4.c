#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern int jj;
extern int l;
extern int k;
extern int lb;
extern int lub;
extern int n1;
extern double **in_v;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0 , l = lub , k = lb - i; i < lb; i++ , l-- , k--) {
    double temp_local;
    for (j = n1 - k , jj = n1; j >= 0; j-- , jj--) {
        temp_local = in_v[l][jj];
        in_v[l][jj] = in_v[i][j];
        in_v[i][j] = temp_local;
    }
}
}
