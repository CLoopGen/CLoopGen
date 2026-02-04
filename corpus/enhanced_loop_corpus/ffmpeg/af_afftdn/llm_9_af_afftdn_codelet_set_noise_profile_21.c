#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double temp[15];
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int m = 0; m < 15; m++) {
        sum += temp[m] * temp[m]; // Square each element before adding
        sum += temp[m] * 0.5;     // Add a scaled version to increase operations
    }
}
