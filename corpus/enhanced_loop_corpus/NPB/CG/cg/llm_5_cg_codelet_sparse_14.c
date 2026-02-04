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
    for (nza = 1; nza <= nnza; nza++) {
        j = arow[nza] - firstrow + 1;
        if (j < 1) continue;
        k = rowstr[j];
        a[k] = aelt[nza];
        colidx[k] = acol[nza];
        rowstr[j] += 1;
    }
}
