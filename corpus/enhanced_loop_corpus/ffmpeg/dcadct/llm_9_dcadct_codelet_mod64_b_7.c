#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *input;
extern int *output;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i += 2) {
        output[i/2] = input[i] + input[i + 1] + input[16 + i] + input[17 + i];
    }
}
