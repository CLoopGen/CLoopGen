#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *input;
extern int *output;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        int temp = input[8 + i];
        if (temp > 0)
            output[i] = input[i] + temp;
        else
            output[i] = input[i];
    }
}
