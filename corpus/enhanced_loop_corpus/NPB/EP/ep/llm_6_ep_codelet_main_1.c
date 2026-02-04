#include <stdio.h>

extern  double x[131072];
extern int i;



void loop(){
    for (i = 0; i < 2 * (1 << 16); i += 2) {
        x[i] = -9.9999999999999997E+98;
        if (i + 1 < 2 * (1 << 16)) {
            x[i + 1] = -9.9999999999999997E+98;
        }
    }
}
