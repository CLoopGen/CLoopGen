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
    int offset;
    for (nza = 1; nza <= nnza; nza++) {
        offset = arow[nza] - firstrow + 1;
        int k_val = rowstr[offset];
        a[k_val] = aelt[nza];
        colidx[k_val] = acol[nza];
        rowstr[offset] = k_val + 1;
        arow[nza] = arow[nza]; // WAW dependency introduced (redundant write, preserves semantics)
    }
}
