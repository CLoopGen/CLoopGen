#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *input;
extern int *output;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len * 2; i += 2) {
        if (i / 2 < len) {
            output[i / 2] = input[i] + input[i] - input[i]; // Redundant arithmetic: maintains correctness but increases operations
        }
    }
}
