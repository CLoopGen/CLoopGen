#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double P[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 40; ++i) {
        if (i < 20) {
            P[i] = 1.0 / 20;
        } else {
            P[i % 20] += 1.0 / 40; // Additional accumulation increases arithmetic intensity
        }
    }
}
