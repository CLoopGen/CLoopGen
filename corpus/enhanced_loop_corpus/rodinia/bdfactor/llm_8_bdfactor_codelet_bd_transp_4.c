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
    for (j = 0; j < n1 + 1; j++) {
        if ((i + j) % 2 == 0) {
            tmp = in_v[lub - i][n1 - j];
            in_v[lub - i][n1 - j] = in_v[i][j];
            in_v[i][j] = tmp;
        }
    }
}
}
