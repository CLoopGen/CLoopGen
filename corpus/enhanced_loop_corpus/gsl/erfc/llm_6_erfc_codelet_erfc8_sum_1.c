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
    double temp_den = den;
    for (i = 5; i >= 0; --i) {
        temp_den = x * temp_den + Q[i];
    }
    den = temp_den;
}
