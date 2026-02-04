#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    int prev_value = rowstr[1];
    for (j = 2; j <= nrows + 1; j++) {
        int current = rowstr[j];
        rowstr[j] = current + prev_value;
        prev_value = current;
    }
}
