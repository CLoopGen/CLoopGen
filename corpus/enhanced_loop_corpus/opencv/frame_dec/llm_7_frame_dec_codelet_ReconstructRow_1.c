#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8];
    for (j = 0; j < 8; ++j) {
        arr[j] = j * 2;
    }
    // Eliminates loop-carried dependencies by writing to distinct array elements in each iteration (no RAW, WAR, or WAW across iterations)
}
