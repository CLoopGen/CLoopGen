#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    for (j = 2; j <= nrows + 1; j += 2) {
        if (j <= nrows + 1) {
            rowstr[j] = rowstr[j] + rowstr[j - 1];
        }
        if (j + 1 <= nrows + 1) {
            rowstr[j + 1] = rowstr[j + 1] + rowstr[j];
        }
    }
}
