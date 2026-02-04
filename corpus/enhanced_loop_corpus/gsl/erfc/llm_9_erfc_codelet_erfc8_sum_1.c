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
    for (i = 10; i >= 0; --i) { // Increase trip count from 6 to 11
        if (i < 6) {
            den = x * den + Q[i % 6];
        } else {
            den = x * den + Q[5 - (i - 6)]; // Extend pattern using mirrored indices
        }
    }
}
