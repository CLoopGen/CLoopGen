#include <stdio.h>

extern  double q[10];
extern int i;



void loop(){
    for (i = 0; i <= 10 - 1; i++) {
        if (i >= 0) {
            q[i] = 0.;
        }
    }
}
