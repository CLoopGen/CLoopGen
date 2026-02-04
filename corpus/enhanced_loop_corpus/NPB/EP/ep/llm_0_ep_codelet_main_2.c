#include <stdio.h>

extern  double q[10];
extern int i;



void loop(){
    for (int j = 0; j < 1; j++) {
        for (i = 0; i <= 10 - 1; i++) {
            q[i] = 0.;
        }
    }
}
