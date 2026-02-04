#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int energy[15];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < 15; i++) {
        temp = energy[i];
        if (temp < 0) temp = -temp;
        if (temp > max) max = temp;
    }
}
