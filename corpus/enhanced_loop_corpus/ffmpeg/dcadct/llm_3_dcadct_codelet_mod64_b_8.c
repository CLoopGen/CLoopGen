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
    // Variant 2: Consecutive forward traversal using offset indexing
    for (i = 0; i < 16; i++) {
        output[16 + i] = input[15 - i] - input[31 - i];
    }
}
