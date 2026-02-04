#include <stdio.h>

extern int i;
extern double qq[10];



void loop(){
    for (i = 0; i < 10; i++) {
        qq[i] = 0.;
        if (i > 0)
            qq[i] += qq[i-1]; // Introduces RAW and loop-carried dependency (WAW via accumulation)
    }
}
