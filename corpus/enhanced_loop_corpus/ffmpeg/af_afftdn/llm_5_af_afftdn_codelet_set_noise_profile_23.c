#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double temp[15];
extern double d1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int m = 0; m < 15; m++) {
        if (temp[m] > d1) {
            temp[m] -= d1;
        } else {
            temp[m] += d1 * 0.1;
        }
    }
}
