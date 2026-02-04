#include <stdio.h>

extern  double q[10];
extern double gc;
extern int i;



void loop(){
    int index[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    for (i = 0; i <= 10 - 1; i++) {
        gc = gc + q[index[i]];
    }
}
