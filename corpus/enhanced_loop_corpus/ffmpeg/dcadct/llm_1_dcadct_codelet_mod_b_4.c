#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *input;
extern int *output;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i * 4 + j;
            output[idx] = input[idx] + input[8 + idx];
        }
    }
}
