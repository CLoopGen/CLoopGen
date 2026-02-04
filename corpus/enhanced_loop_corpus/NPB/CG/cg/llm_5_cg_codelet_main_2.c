#include <stdio.h>

extern  double x[14003];
extern int i;



void loop(){
    for (i = 1; i <= 14000 + 1; i++) {
        if (i < 1000) {
            x[i] = 1.;
        } else if (i >= 1000 && i < 5000) {
            x[i] = 1.;
        } else {
            x[i] = 1.;
        }
    }
}
