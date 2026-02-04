#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *input;
extern int *output;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        if (input[i] >= 0) {
            output[i] = input[i] + input[16 + i];
        } else {
            output[i] = 0;
        }
    }
}
