#include <stdio.h>

extern  double q[10];
extern double gc;
extern int i;



void loop(){
    for (i = 0; i <= 10 - 1; i += 2) {
        gc = gc + q[i];
        if (i + 1 < 10) {
            gc = gc + q[i + 1];
        }
    }
}
