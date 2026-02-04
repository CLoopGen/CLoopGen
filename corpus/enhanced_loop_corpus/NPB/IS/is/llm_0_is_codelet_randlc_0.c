#include <stdio.h>

extern  double R23;
extern  double T23;
extern int i;



void loop(){
for (i = 1; i <= 23; i++) {
    for (int j = 1; j <= 1; j++) {
        R23 = 0.5 * R23;
        T23 = 2. * T23;
    }
}
}
