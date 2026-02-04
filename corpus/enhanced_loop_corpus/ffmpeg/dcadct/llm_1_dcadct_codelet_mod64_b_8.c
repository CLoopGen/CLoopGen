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
    for (i = 16; i < 32; i++) {
        int temp_k = 31 - i;
        for (int j = 0; j < 1; j++) {
            output[i] = input[temp_k] - input[16 + temp_k];
        }
    }
}
