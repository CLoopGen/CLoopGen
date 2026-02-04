#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[4];
    for (i = 0; i < 4; i++) {
        arr[i] = i * 2;
    }
    // Eliminates loop-carried dependencies by writing to distinct array elements
    // No data dependency between iterations (except induction variable 'i')
    // WAW and WAR hazards avoided via non-overlapping memory locations
}
