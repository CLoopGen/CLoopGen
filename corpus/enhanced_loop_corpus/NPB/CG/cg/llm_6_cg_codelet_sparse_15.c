#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    int temp;
    for (j = nrows; j >= 1; j--) {
        temp = rowstr[j];
        rowstr[j + 1] = temp;
    }
}
