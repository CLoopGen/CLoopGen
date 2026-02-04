#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int l;
extern  double x;
extern double bkp;
extern double bk;
extern double bkm;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *temp_bk = (double*)malloc(l * sizeof(double));
    if (!temp_bk) exit(1);
    temp_bk[0] = bk;
    for (j = 1; j < l; j++) {
        temp_bk[j] = (2 * (j + 1) + 1) / x * temp_bk[j - 1] + ((j > 1) ? temp_bk[j - 2] : bkm);
    }
    bkp = temp_bk[l - 1];
    bkm = (l > 1) ? temp_bk[l - 2] : bkm;
    bk = bkp;
    free(temp_bk);
}
