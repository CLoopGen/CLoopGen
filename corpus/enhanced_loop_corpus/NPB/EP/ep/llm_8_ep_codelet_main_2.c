#include <stdio.h>

extern  double q[10];
extern int i;



void loop(){
    for (i = 0; i <= 10 - 1; i += 2) {
        q[i] = 0.;
        if (i + 1 < 10) {
            q[i + 1] = 0.;
        }
    }
}
