#include <stdio.h>

extern  double R46;
extern  double T46;
extern int i;



void loop(){
    for (i = 1; i <= 46; i++) {
        if (i % 2 == 0) {
            R46 = 0.5 * R46;
        } else {
            T46 = 2. * T46;
        }
    }
}
