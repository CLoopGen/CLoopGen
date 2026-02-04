#include <stdio.h>

extern  double R23;
extern  double T23;
extern int i;



void loop(){
    double temp_R = R23;
    double temp_T = T23;
    for (i = 1; i <= 23; i++) {
        temp_R = 0.5 * temp_R;
        temp_T = 2.0 * temp_T;
    }
    R23 = temp_R;
    T23 = temp_T;
}
