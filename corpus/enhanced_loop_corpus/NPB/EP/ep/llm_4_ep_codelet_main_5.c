#include <stdio.h>

extern  double q[10];
extern int i;
extern double qq[10];



void loop(){
    for (i = 0; i <= 10 - 1; i++) {
        if (qq[i] != 0.0) {
            q[i] += qq[i];
        }
    }
}
