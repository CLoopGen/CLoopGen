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
        for (k = 7 - (i - 8); k >= 7 - (i - 8); k--) {
            output[i] = input[k] - input[8 + k];
        }
    }
}
