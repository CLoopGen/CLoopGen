#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    t[0] = 1.23;
    for (n = 1; n < 50; n++) {
        t[n] = t[n-1] * 0.0; // Introduces RAW and loop-carried dependence; t[n] depends on t[n-1], though value remains 0 after first iteration
    }
}
