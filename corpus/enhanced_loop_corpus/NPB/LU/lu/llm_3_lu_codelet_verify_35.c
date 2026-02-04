#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    // Variant 2: Reverse order (consecutive but descending) memory access
    for (m = 4; m >= 0; m--) {
        xcrref[m] = 1.;
        xceref[m] = 1.;
    }
}
