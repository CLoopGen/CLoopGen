#include <stdio.h>

extern  double R23;
extern  double T23;
extern int i;



void loop(){
    double local_R = R23;
    double local_T = T23;
    for (i = 1; i <= 23; i++) {
        if (i % 2 == 1) {
            local_R = 0.5 * local_R;
        } else {
            local_T = 2.0 * local_T;
        }
    }
    R23 = local_R;
    T23 = local_T;
}
