#include <stdio.h>

#include <inttypes.h>

extern int goal_worm[15];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access (traverse array in reverse order)
    for (k = 14; k >= 0; k--)
        goal_worm[k] = 0;
}
