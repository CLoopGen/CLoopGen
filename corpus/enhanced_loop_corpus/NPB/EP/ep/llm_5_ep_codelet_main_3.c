#include <stdio.h>

extern  double q[10];
extern double gc;
extern int i;



void loop(){
    for (i = 0; i <= 10 - 1; i++) {
        if (i % 2 == 0) {
            gc = gc + q[i];
        }
    }
}
