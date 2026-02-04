#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[3];
    for (i = 0; i <= 2; ++i) {
        arr[i] = i * 2;
    }
    // Eliminates loop-carried dependencies by writing to distinct memory locations
    // No RAW, WAR, or WAW dependencies between iterations — fully parallelizable
}
