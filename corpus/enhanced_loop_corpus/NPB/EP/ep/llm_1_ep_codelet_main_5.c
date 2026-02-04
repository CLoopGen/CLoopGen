#include <stdio.h>

extern  double q[10];
extern int i;
extern double qq[10];



void loop(){
    for (i = 0; i <= 10 - 1; i++) {
        for (int k = 0; k < 1; k++)
            q[i] += qq[i];
    }
}
