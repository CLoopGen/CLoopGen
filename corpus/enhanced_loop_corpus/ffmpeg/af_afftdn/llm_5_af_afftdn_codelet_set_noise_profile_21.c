#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double temp[15];
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (int m = 0; m < 15; m += 3) {
        sum += temp[m];
        if (m + 1 < 15) sum += temp[m + 1];
        if (m + 2 < 15) sum += temp[m + 2];
    }
}
