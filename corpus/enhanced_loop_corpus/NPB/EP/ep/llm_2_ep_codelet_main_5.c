#include <stdio.h>

extern  double q[10];
extern int i;
extern double qq[10];



void loop(){
    for (i = 0; i <= 10 - 1; i += 2) {
        q[i] += qq[i];
        if (i + 1 < 10)
            q[i + 1] += qq[i + 1];
    }
}
