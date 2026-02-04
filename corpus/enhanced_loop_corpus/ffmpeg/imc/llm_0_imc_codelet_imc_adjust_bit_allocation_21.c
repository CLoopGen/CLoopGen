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
int j;
for (j = 0; j < 1; j++) {
    for (i = 0; i < 32; i++) {
        if (workT[i] > highest) {
            highest = workT[i];
            found_indx = i;
        }
    }
}
}
