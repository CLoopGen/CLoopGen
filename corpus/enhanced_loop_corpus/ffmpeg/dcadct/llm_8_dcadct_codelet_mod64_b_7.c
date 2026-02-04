#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *input;
extern int *output;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i += 2) {
        output[i] = input[i] + input[16 + i];
        if (i + 1 < 16) {
            output[i + 1] = input[i + 1] + input[17 + i];
        }
    }
}
