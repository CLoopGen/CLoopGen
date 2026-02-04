#include <stdio.h>

extern  double R46;
extern  double T46;
extern int i;



void loop(){
for (i = 1; i <= 46; i++) {
    R46 = 0.5 * R46 + 0.1 * R46;
    T46 = 2.0 * T46;
    R46 = R46 - 0.05 * R46;
    T46 = T46 + 0.01 * T46;
}
}
