#include <stdio.h>

extern  double q[10];
extern double gc;
extern int i;



void loop(){
    double temp = gc;
    for (i = 0; i <= 10 - 1; i++) {
        temp = temp + q[i];
    }
    gc = temp;
}
