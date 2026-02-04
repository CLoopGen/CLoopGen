#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    for (j = nrows; j >= 1; j--) {
        if (rowstr[j] != 0) {
            rowstr[j + 1] = rowstr[j];
        }
    }
}
