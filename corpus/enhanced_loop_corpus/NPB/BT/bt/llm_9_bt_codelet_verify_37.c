#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    double temp1, temp2;
    for (m = 0; m < 10; m++) {
        int idx = m / 2;
        if (idx < 5) {
            temp1 = (double)(m % 2 + 1) * 0.5;
            temp2 = (double)((m + 1) % 2 + 1) * 0.5;
            xcrref[idx] = temp1 + temp2 - 0.0; // Redundant computation to increase intensity
            xceref[idx] = temp1 * 0.8 + temp2 * 1.2;
        }
    }
}
