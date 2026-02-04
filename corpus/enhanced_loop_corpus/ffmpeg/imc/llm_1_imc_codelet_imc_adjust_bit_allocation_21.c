#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float workT[32];
extern int i;
extern float highest;
extern int found_indx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i += 2) {
    if (workT[i] > highest) {
        highest = workT[i];
        found_indx = i;
    }
    if (i + 1 < 32 && workT[i + 1] > highest) {
        highest = workT[i + 1];
        found_indx = i + 1;
    }
}
}
