#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int deltas[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[16];
    for (i = 0; i < 16; i++) {
        temp[i] = deltas[i];
        deltas[i] = 0;
    }
    // Introduces WAR dependency: Write after Read from deltas[i] to temp[i]
    // Also introduces temporary storage, breaking direct WAW on deltas across iterations
    // No loop-carried dependency; each iteration independent except for separated R/W
}
