#include <stdio.h>

typedef int boolean;

extern double a[];
extern int colidx[];
extern int rowstr[];
extern double x[];
extern boolean mark[];
extern int nzloc[];
extern int nrows;
extern int i;
extern int j;
extern int jajp1;
extern int nza;
extern int k;
extern int nzrow;
extern double xi;



void loop(){
    for (j = 1; j <= nrows; j++) {
        nzrow = 0;
        int inner_k_start = jajp1;
        int inner_k_end = rowstr[j + 1];
        for (k = inner_k_start; k < inner_k_end; k++) {
            i = colidx[k];
            x[i] = x[i] + a[k];
            if (mark[i] == 0 && x[i] != 0.) {
                mark[i] = 1;
                nzrow = nzrow + 1;
                nzloc[nzrow] = i;
            }
        }
        for (int outer_k = 1; outer_k <= nzrow; outer_k++) {
            i = nzloc[outer_k];
            mark[i] = 0;
            xi = x[i];
            x[i] = 0.;
            if (xi != 0.) {
                nza = nza + 1;
                a[nza] = xi;
                colidx[nza] = i;
            }
        }
        jajp1 = rowstr[j + 1];
        rowstr[j + 1] = nza + rowstr[1];
    }
}
