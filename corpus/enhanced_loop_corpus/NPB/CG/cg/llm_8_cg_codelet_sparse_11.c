#include <stdio.h>

extern int rowstr[];
extern int arow[];
extern int firstrow;
extern int nnza;
extern int j;
extern int nza;



void loop(){
    for (nza = 1; nza <= nnza; nza += 2) {
        if (nza + 1 <= nnza) {
            int j1 = (arow[nza] - firstrow + 1) + 1;
            int j2 = (arow[nza + 1] - firstrow + 1) + 1;
            rowstr[j1] += 1;
            rowstr[j2] += 1;
        } else {
            j = (arow[nza] - firstrow + 1) + 1;
            rowstr[j] = rowstr[j] + 1;
        }
    }
}
