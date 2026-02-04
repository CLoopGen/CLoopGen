#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    for (j = nrows; j >= 1; j--) {
        rowstr[j + 1] = rowstr[j];
        if (j == nrows / 2) {
            rowstr[j + 1] += 1;
        }
    }
}
