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
        int temp_nza = nza;
        for (k = jajp1; k < rowstr[j + 1]; k++) {
            i = colidx[k];
            double temp_val = a[k];
            x[i] = x[i] + temp_val;
            if (mark[i] == 0 && x[i] != 0.) {
                mark[i] = 1;
                nzrow = nzrow + 1;
                nzloc[nzrow] = i;
            }
        }
        for (k = 1; k <= nzrow; k++) {
            i = nzloc[k];
            mark[i] = 0;
            xi = x[i];
            x[i] = 0.;
            if (xi != 0.) {
                temp_nza = temp_nza + 1;
                a[temp_nza] = xi;
                colidx[temp_nza] = i;
            }
        }
        nza = temp_nza;
        jajp1 = rowstr[j + 1];
        rowstr[j + 1] = nza + rowstr[1];
    }
}
