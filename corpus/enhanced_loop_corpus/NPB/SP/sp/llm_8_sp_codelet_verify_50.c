#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m += 1) {
        xcrref[m] = 1.0 + 2.0 * 3.0 - 1.0;
        xceref[m] = (1.0 + 1.0) * 2.0 / 2.0;
    }
}
