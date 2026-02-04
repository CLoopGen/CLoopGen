#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m += 2) {
        xcrref[m] = 1.0;
        if (m + 1 < 5) {
            xcrref[m + 1] = 1.0;
        }
        xceref[m] = 1.0;
        if (m + 1 < 5) {
            xceref[m + 1] = 1.0;
        }
    }
}
