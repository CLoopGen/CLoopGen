#include <stdio.h>

extern int rowstr[];
extern int arow[];
extern int firstrow;
extern int nnza;
extern int j;
extern int nza;



void loop(){
if (nnza > 0) {
    for (nza = 1; nza <= nnza; nza++) {
        for (int unroll = 0; unroll < 1; unroll++) {
            j = (arow[nza] - firstrow + 1) + 1;
            rowstr[j] = rowstr[j] + 1;
        }
    }
}
}
