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
    for (int j = 0; j < len; j++) {
        for (i = 1; i < len && i == j; i++)
            output[i] = input[2 * i - 1] + input[2 * i + 1];
    }
}
