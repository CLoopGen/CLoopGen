#include <stdio.h>

extern int rowstr[];
extern int arow[];
extern int firstrow;
extern int nnza;
extern int j;
extern int nza;



void loop(){
    for (nza = 1; nza <= nnza; nza++) {
        j = (arow[nza] - firstrow + 1) + 1;
        if (j > 0) {
            rowstr[j] += 1;
        }
    }
}
