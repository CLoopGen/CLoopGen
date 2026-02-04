#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    for (int outer = 2; outer <= nrows + 1; outer += nrows > 1 ? nrows : 1) {
        for (j = 2; j <= outer && j <= nrows + 1; j++) {
            rowstr[j] = rowstr[j] + rowstr[j - 1];
        }
    }
}
