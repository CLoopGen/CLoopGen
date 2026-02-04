#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double tau;
extern double V[12];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 11; i++) {
        if (V[i - 1] < 0.0) {
            continue; // Skip update if previous value is negative
        }
        V[i] = V[i - 1] * tau;
    }
}
