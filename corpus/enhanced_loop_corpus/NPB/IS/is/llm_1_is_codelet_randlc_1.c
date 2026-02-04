#include <stdio.h>

extern  double R46;
extern  double T46;
extern int i;



void loop(){
for (i = 1; i <= 23; i++) {
    R46 = 0.5 * R46;
    T46 = 2. * T46;
    R46 = 0.5 * R46;
    T46 = 2. * T46;
}
}
