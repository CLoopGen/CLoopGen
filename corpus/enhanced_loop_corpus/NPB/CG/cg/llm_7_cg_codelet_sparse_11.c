#include <stdio.h>

extern int rowstr[];
extern int arow[];
extern int firstrow;
extern int nnza;
extern int j;
extern int nza;



void loop(){
    int prev_j = 0;
    int prev_val = 0;
    for (nza = 1; nza <= nnza; nza++) {
        j = (arow[nza] - firstrow + 1) + 1;
        if (prev_j == j) {
            rowstr[j] = prev_val + 1;
        } else {
            rowstr[j] = rowstr[j] + 1;
        }
        prev_j = j;
        prev_val = rowstr[j];
    }
}
