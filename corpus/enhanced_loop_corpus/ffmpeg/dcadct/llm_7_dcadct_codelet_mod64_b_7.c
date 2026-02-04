#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *input;
extern int *output;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[16];
    for (i = 0; i < 16; i++) {
        temp[i] = input[i];
    }
    for (i = 0; i < 16; i++) {
        output[i] = temp[i] + input[16 + i];
    }
}
