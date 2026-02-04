#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int deltas[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[16];
    for (i = 0; i < 16; i++)
        temp[i] = 0; // Remove direct write to shared array
    for (i = 0; i < 16; i++)
        deltas[i] = temp[i]; // Eliminate all loop-carried dependencies; break WAW on deltas
}
