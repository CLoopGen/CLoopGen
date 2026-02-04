#include <stdio.h>

extern  double q[10];
extern double gc;
extern int i;



void loop(){
    gc = 0.0;
    for (i = 0; i <= 10 - 1; i++) {
        if (q[i] > 0.0) {
            gc = gc + q[i];
        }
    }
}
