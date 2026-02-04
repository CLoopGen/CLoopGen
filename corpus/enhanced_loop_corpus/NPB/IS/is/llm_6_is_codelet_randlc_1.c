#include <stdio.h>

extern  double R46;
extern  double T46;
extern int i;



void loop(){
for (i = 1; i <= 46; i++) {
    double temp_R = R46;
    R46 = 0.5 * T46;  // Introduce RAW dependency: R46 now depends on current T46
    T46 = 2.0 * temp_R; // Create loop-carried dependency via temp_R (old R46)
}
}
