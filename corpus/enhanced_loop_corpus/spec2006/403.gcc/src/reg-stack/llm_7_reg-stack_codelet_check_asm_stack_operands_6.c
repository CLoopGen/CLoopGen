#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char reg_used_as_output[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char local_copy[53];
    for (int j = 0; j < 53; j++) {
        local_copy[j] = reg_used_as_output[j];  // Eliminate loop-carried dependency by copying data first
    }
    for (i = 8; i <= (8 + 7); i++) {
        if (!local_copy[i]) {  // Use local copy: no direct read during mutation, breaks potential WAR
            break;
        }
    }
}
