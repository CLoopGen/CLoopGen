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
    int temp1, temp2;
    for (i = 0; i < len; i++) {
        temp1 = input[2 * i];
        temp2 = input[2 * i + 1];
        output[i] = temp1 + temp2;
    }
}
