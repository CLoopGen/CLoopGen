#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern unsigned short num[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW dependency by splitting the write into two stages
    // and introducing an intermediate computation that depends on previous iteration's write.
    unsigned short temp[9];
    for (i = 0; i < (6 + 3); i++) {
        temp[i] = equot[i] + 1;  // Intermediate modification
    }
    for (i = 0; i < (6 + 3); i++) {
        num[i] = temp[i] - 1;    // Reverses the above, but creates WAW if num and equot overlap
    }
}
