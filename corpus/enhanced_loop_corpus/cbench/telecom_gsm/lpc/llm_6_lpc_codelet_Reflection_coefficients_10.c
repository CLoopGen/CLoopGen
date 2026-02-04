#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern int i;
extern word ACF[9];
extern word K[9];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW dependency by splitting the assignment and introducing a temporary computation
    // Also introduces a RAW dependency via temp array
    word temp[9];
    for (i = 1; i <= 7; i++) {
        temp[i] = ACF[i];
    }
    for (i = 1; i <= 7; i++) {
        K[i] = temp[i]; // WAW on K[i], loop-carried due to split
    }
}
