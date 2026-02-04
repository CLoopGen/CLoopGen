#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    int *base = &rowstr[1];
    for (j = nrows; j >= 1; j--) {
        base[j + 1] = base[j];
    }
}
