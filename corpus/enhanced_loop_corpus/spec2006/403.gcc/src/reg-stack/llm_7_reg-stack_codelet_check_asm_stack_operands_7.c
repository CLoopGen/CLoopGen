#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char reg_used_as_output[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_copy[53];
    for (int j = 0; j < 53; j++)
        local_copy[j] = reg_used_as_output[j]; // Eliminate potential WAR by reading early
    for (; i < (8 + 7) + 1; i++)
        if (local_copy[i]) // Use local copy to remove loop-carried dependence on global
            break;
}
