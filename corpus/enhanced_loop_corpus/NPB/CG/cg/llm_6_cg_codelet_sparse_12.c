#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    int temp = rowstr[2];
    for (j = 2; j <= nrows + 1; j++) {
        if (j > 2) {
            temp = rowstr[j] + rowstr[j - 1];
            rowstr[j] = temp;
        } else {
            rowstr[j] = rowstr[j] + rowstr[j - 1];
        }
    }
}
