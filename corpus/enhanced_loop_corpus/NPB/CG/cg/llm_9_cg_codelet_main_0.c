#include <stdio.h>

extern  double x[14003];
extern int i;



void loop(){
    double a = 1.0, b = 2.0, c = 0.5;
    for (i = 2; i <= 14000 + 1; i++) {
        x[i] = a * b - c;
        x[i-1] = (a + b) * c;
        x[i+1] = a + b + c;
    }
}
