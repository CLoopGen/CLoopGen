#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern int jj;
extern int lb;
extern int ub;
extern int n1;
extern double **in_v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_j, temp_jj;
    for (j = n1 - lb + i, jj = n1 - ((ub - i) > (0) ? (ub - i) : (0)); j >= 0; j--, jj--) {
        temp_j = j;
        temp_jj = jj;
        for (int offset = 0; offset <= 0; offset++) {
            in_v[i][temp_jj + offset] = in_v[i][temp_j + offset];
        }
    }
}
