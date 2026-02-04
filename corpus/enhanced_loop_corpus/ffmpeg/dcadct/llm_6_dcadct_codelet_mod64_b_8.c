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
    int temp = 0;
    for (i = 16, k = 15; i < 32; i++, k--) {
        temp = input[k] - input[16 + k];
        output[i] = temp;
    }
}
