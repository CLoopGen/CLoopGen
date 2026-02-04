#include <stdio.h>

extern  double q[10];
extern double gc;
extern int i;



void loop(){
    for (i = 0; i <= 10 - 1; i++) {
        for (int k = 0; k < 1; k++) {
            gc = gc + q[i];
        }
    }
}
