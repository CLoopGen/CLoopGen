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
        output[2*i]     = input[2*i] + input[16 + 2*i];
        output[2*i + 1] = input[2*i + 1] + input[17 + 2*i];
    }
}
