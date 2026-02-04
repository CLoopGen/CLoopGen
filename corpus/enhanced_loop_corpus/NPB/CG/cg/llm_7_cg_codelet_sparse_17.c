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
        int local_jajp1 = jajp1;
        int local_row_end = rowstr[j + 1];
        for (k = local_jajp1; k < local_row_end; k++) {
            i = colidx[k];
            double update = a[k];
            if (x[i] == 0.0) {
                x[i] = update;
            } else {
                x[i] += update;
            }
            if (mark[i] == 0) {
                mark[i] = 1;
                nzrow++;
                nzloc[nzrow] = i;
            }
        }
        for (k = nzrow; k >= 1; k--) {
            i = nzloc[k];
            xi = x[i];
            x[i] = 0.0;
            mark[i] = 0;
            if (xi != 0.0) {
                nza++;
                a[nza] = xi;
                colidx[nza] = i;
            }
        }
        jajp1 = local_row_end;
        rowstr[j + 1] = nza + rowstr[1];
    }
}
