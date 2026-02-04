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
for (i = 0; i < lb; i += 2) {
    k = lb - i;
    l = lub - i;
    for (j = n1 - k; j >= 0; j -= 2) {
        jj = n1 - (n1 - k - j);
        tmp = in_v[l][jj];
        in_v[l][jj] = in_v[i][j];
        in_v[i][j] = tmp;
        if (i + 1 < lb && j + 1 <= n1 - k) {
            tmp = in_v[l][jj + 1];
            in_v[l][jj + 1] = in_v[i + 1][j + 1];
            in_v[i + 1][j + 1] = tmp;
        }
    }
}
}
