#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    for (int k = 0; k < 1; k++) {
        for (j = nrows; j >= 1; j--) {
            rowstr[j + 1] = rowstr[j];
        }
    }
}
