#include <stdio.h>

extern  double q[10];
extern int i;
extern double qq[10];



void loop(){
    for (i = 0; i <= 10 - 1; i++) {
        q[i] += qq[i];
        qq[i] = q[i]; // Introduce WAW and WAR dependency, create loop-carried dependence
    }
}
