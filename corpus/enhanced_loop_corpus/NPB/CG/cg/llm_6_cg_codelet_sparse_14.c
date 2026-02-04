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
    int temp_j, temp_k;
    for (nza = 1; nza <= nnza; nza++) {
        temp_j = arow[nza] - firstrow + 1;
        temp_k = rowstr[temp_j];
        a[temp_k] = aelt[nza];
        colidx[temp_k] = acol[nza];
        rowstr[temp_j] = temp_k + 1;
    }
}
