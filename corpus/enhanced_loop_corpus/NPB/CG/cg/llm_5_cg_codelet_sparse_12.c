#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    for (j = 2; j <= nrows + 1; j++) {
        if (j % 2 == 0) {
            rowstr[j] = rowstr[j] + rowstr[j - 1];
        } else {
            continue;
        }
    }
}
