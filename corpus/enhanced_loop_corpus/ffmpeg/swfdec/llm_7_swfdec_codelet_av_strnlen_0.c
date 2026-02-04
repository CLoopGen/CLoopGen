#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        if (!s[i]) break;
        // Move the condition check inside the loop body to eliminate loop-carried dependency through the loop bound
        // Original loop had combined test in header; now we separate termination logic
        // This removes the WAW hazard on control flow by making exit explicit
    }
}
