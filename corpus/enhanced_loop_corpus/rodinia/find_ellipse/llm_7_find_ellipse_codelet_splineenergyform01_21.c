#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *dindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N - 2; i++) {
        int temp = i + 2;
        dindex[i + 2] = temp; // Removes potential WAW on dindex[i], shifts write index forward
        // Eliminates loop-carried dependency by decoupling write location from iteration order
    }
}
