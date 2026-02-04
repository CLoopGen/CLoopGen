#include <stdio.h>

extern  double errnm[5];
extern int m;



void loop(){
    for (int depth = 0; depth < 1; depth++) {
        for (m = 0; m < 5; m++) {
            errnm[m] = 0.;
        }
    }
}
