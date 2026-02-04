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
    for (int block = 0; block < nnza; block += 1) {  // Outer loop with unit stride, effectively preserving original logic
        nza = block + 1;
        j = arow[nza] - firstrow + 1;
        k = rowstr[j];
        a[k] = aelt[nza];
        colidx[k] = acol[nza];
        rowstr[j] = rowstr[j] + 1;
    }
}
