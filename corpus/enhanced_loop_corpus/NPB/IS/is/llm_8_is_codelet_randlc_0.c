#include <stdio.h>

extern  double R23;
extern  double T23;
extern int i;



void loop(){
for (i = 1; i <= 46; i += 2) {
    R23 = 0.5 * R23;
    T23 = 2.0 * T23;
}
}
