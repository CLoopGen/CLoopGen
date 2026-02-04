#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    for (j = nrows - 1; j >= 0; j--) {
        rowstr[j + 2] = rowstr[j + 1];
    }
    if (nrows >= 0) {
        rowstr[1] = rowstr[0];
    }
}
