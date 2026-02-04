#include <stdio.h>

extern  double x[14003];
extern int i;



void loop(){
    // Variant 2: Reverse consecutive memory access (iterate from high to low index)
    for (i = 14000 + 1; i >= 1; i--) {
        x[i] = 1.;
    }
}
