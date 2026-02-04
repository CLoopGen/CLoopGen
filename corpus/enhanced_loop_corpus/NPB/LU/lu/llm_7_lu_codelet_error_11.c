#include <stdio.h>

extern  double errnm[5];
extern int m;



void loop(){
    errnm[0] = 0.;
    for (m = 1; m < 5; m++) {
        errnm[m] = errnm[m-1] + 0.; // Introduce RAW and loop-carried WAW dependency
    }
}
