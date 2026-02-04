#include <stdio.h>

extern int rowstr[];
extern int arow[];
extern int firstrow;
extern int nnza;
extern int j;
extern int nza;



void loop(){
    for (nza = 1; nza <= nnza * 2; nza++) {
        j = (arow[(nza % nnza) + 1] - firstrow + 1) + 1;
        rowstr[j] = rowstr[j] + 1;
        rowstr[j] = rowstr[j] + 1; // Double the increment to increase arithmetic intensity
    }
}
