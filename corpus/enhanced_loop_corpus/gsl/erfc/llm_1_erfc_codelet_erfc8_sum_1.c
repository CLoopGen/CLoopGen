#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double Q[];
extern double den;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 5; i >= 0; --i) {
    if (i % 2 == 0) {
        den = x * den + Q[i];
    } else {
        den = den + Q[i];
    }
}
}
