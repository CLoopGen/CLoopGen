#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int others[257];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[257];
    for (i = 0; i < 257; i++) {
        temp[i] = -1; // Remove direct memory write, store locally first (eliminates WAW on others[])
    }
    for (i = 0; i < 257; i++) {
        others[i] = temp[i]; // Separate load and store phases: breaks loop-carried dependencies
    }
}
