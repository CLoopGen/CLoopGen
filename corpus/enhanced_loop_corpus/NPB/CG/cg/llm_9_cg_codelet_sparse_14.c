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
    int nza, j, k, offset;
    for (nza = 1; nza <= nnza; nza++) {
        for (offset = 0; offset < 3; offset++) {
            j = arow[nza] - firstrow + 1;
            k = rowstr[j] + offset;
            a[k] = aelt[nza] + offset * 0.1;
            colidx[k] = acol[nza] + offset;
        }
        rowstr[j] = rowstr[j] + 3;
    }
}
