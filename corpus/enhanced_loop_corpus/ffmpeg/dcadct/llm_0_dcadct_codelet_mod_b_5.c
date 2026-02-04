#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *input;
extern int *output;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i < 16; i++) {
        int temp_k = 7 - (i - 8);
        output[i] = input[temp_k] - input[8 + temp_k];
    }
}
