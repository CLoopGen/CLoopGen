#include <stdio.h>

extern int rowstr[];
extern int nrows;
extern int j;



void loop(){
    int indices[2] = {0, 1};
    for (j = nrows; j >= 1; j--) {
        rowstr[j + indices[1]] = rowstr[j + indices[0]];
    }
}
