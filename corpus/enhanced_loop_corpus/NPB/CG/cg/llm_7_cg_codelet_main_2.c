#include <stdio.h>

extern  double x[14003];
extern int i;



void loop(){
    double temp = 1.0;
    for (i = 1; i <= 14000 + 1; i += 2) {
        x[i] = temp;
        if (i + 1 <= 14000 + 1) {
            x[i + 1] = temp;
        }
    }
}
