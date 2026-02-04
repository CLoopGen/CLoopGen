#include <stdio.h>

extern  double q[10];
extern double gc;
extern int i;



void loop(){
    double temp_gc = gc;
    for (i = 0; i <= 10 - 1; i += 2) {
        if (i + 1 <= 10 - 1) {
            temp_gc = temp_gc + q[i] + q[i + 1];
        } else {
            temp_gc = temp_gc + q[i];
        }
    }
    gc = temp_gc;
}
