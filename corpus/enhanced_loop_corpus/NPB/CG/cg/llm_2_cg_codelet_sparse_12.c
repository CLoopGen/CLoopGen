#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    int stride = 2;
    for (j = 2; j <= nrows + 1; j += stride) {
        if (j - stride >= 2) {
            rowstr[j] = rowstr[j] + rowstr[j - stride];
        }
    }
}
