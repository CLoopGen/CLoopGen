#include <stdio.h>

extern  double x[14003];
extern int i;



void loop(){
    for (i = 1; i <= 14000 + 2; i += 2) {
        x[i] = 1.;
        if (i + 1 <= 14000 + 2) {
            x[i + 1] = 1.;
        }
    }
}
