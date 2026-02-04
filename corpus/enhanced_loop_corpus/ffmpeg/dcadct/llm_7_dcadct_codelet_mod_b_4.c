#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *input;
extern int *output;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        output[i] = input[i] + input[i + 1];
    }
    // Introduces a RAW dependency and creates a loop-carried dependency via shifted indexing.
    // Note: This assumes input[9] is valid for i=7, which should be ensured by context.
}
