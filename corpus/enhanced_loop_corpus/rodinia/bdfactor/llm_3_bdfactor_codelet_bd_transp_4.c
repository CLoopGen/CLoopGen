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
    double *row_i = in_v[i];           // Base pointer to row i
    double *row_l = in_v[l];           // Base pointer to row l
    for (j = n1 - k , jj = n1; j >= 0; j-- , jj--) {
        tmp = row_l[jj];
        row_l[jj] = row_i[j];
        row_i[j] = tmp;
    }
}
}
