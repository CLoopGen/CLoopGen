#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to handle valid indices
    for (m = 0; m < 5; m += 2) {
        if (m < 5) {
            xcrref[m] = 1.;
            xceref[m] = 1.;
        }
    }
    // Handle remaining element if any (when m == 4 + 2 would go out of bounds)
    if ((m - 2) + 1 < 5) {
        xcrref[4] = 1.;
        xceref[4] = 1.;
    }
}
