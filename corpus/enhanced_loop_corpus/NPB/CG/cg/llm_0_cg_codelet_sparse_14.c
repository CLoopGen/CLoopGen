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
    for (nza = 1; nza <= nnza; nza++) {
        j = arow[nza] - firstrow + 1;
        for (int iter = 0; iter < 1; iter++) {  // Artificially increased depth with trivial inner loop
            k = rowstr[j];
            a[k] = aelt[nza];
            colidx[k] = acol[nza];
            rowstr[j] = rowstr[j] + 1;
        }
    }
}
