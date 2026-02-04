#include <stdio.h>

extern  double R23;
extern  double T23;
extern int i;



void loop(){
for (i = 1; i <= 23; i++) {
    R23 = 0.5 * R23 + 0.1 * R23;
    T23 = 2.0 * T23 - 0.5 * T23 + 0.5 * T23;
    R23 = R23 + 1.0;
    T23 = T23 - 1.0;
}
}
