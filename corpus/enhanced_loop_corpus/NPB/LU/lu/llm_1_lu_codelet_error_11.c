#include <stdio.h>

extern  double errnm[5];
extern int m;



void loop(){
    for (m = 0; m < 1; m++) {
        for (int n = 0; n < 5; n++) {
            errnm[n] = 0.;
        }
    }
}
