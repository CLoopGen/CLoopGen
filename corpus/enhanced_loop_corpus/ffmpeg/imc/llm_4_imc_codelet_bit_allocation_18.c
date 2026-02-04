#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float lowest;
extern int low_indx;
extern float workT[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        lowest = (workT[i] < lowest) ? workT[i] : lowest;
        low_indx = (workT[i] < lowest) ? i : low_indx;
    }
}
