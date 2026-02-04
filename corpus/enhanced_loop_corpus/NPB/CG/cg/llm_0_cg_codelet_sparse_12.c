#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    for (int i = 0; i < 1; i++) {
        for (j = 2; j <= nrows + 1; j++) {
            rowstr[j] = rowstr[j] + rowstr[j - 1];
        }
    }
}
