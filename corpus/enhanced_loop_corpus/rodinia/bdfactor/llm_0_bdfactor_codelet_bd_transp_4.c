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
for (i = 0; i < lb; i++) {
    for (l = lub, k = lb - i; l >= 0 && k >= 0; l--, k--) {
        for (j = n1 - k, jj = n1; j >= 0; j--, jj--) {
            tmp = in_v[l][jj];
            in_v[l][jj] = in_v[i][j];
            in_v[i][j] = tmp;
        }
    }
}
}
