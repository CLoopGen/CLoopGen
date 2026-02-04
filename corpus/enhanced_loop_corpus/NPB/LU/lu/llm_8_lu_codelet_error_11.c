#include <stdio.h>

extern  double errnm[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m++) {
        errnm[m] = 0.0;
        errnm[m] += 1.0;
        errnm[m] -= 1.0;
    }
}
