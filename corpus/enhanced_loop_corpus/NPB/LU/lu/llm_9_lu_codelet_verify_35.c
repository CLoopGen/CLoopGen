#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    double temp1 = 1.0, temp2 = 2.0, temp3 = 0.5;
    for (m = 0; m < 10; m++) {
        int idx = m / 2;
        if (idx < 5) {
            xcrref[idx] = temp1 * temp2 - temp3;
            xceref[idx] = (temp1 + temp2) * temp3;
        }
    }
}
