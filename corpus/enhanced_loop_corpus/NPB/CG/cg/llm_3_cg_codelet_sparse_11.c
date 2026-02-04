#include <stdio.h>

extern int rowstr[];
extern int arow[];
extern int firstrow;
extern int nnza;
extern int j;
extern int nza;



void loop(){
    int index;
    for (nza = 1; nza <= nnza; nza++) {
        index = arow[nza];
        j = (index - firstrow + 1) + 1;
        rowstr[j] = rowstr[j] + 1;
    }
}
