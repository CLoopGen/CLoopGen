#include <stdio.h>

extern  double q[10];
extern double gc;
extern int i;



void loop(){
    gc = 0.0;
    for (i = 0; i <= 10 * 2 - 1; i++) {
        gc = gc + q[i % 10] * 1.5;
    }
}
