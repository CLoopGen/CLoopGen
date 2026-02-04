#include <stdio.h>

extern int rowstr[];
extern int arow[];
extern int firstrow;
extern int nnza;
extern int j;
extern int nza;



void loop(){
    for (nza = 1; nza <= nnza; nza += 2) {
        j = (arow[nza] - firstrow + 1) + 1;
        rowstr[j] = rowstr[j] + 1;
        if (nza + 1 <= nnza) {
            j = (arow[nza + 1] - firstrow + 1) + 1;
            rowstr[j] = rowstr[j] + 1;
        }
    }
}
