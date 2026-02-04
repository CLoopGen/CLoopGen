#include <stdio.h>

extern double a[];
extern int colidx[];
extern int rowstr[];
extern int arow[];
extern int acol[];
extern double aelt[];
extern int firstrow;
extern int nnza;
extern int j;
extern int nza;
extern int k;



void loop(){
    int nza, j, k;
    for (nza = 1; nza <= nnza; nza += 2) {
        if (nza <= nnza) {
            j = arow[nza] - firstrow + 1;
            k = rowstr[j];
            a[k] = aelt[nza];
            colidx[k] = acol[nza];
            rowstr[j] = k + 1;
        }
        if (nza + 1 <= nnza) {
            j = arow[nza+1] - firstrow + 1;
            k = rowstr[j];
            a[k] = aelt[nza+1];
            colidx[k] = acol[nza+1];
            rowstr[j] = k + 1;
        }
    }
}
