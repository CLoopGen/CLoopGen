#include <stdio.h>

extern  double errnm[5];
extern int m;



void loop(){
    for (m = 0; m < 10; m += 2) {
        int idx = m / 2;
        if (idx < 5) {
            errnm[idx] = 0.0;
        }
    }
}
