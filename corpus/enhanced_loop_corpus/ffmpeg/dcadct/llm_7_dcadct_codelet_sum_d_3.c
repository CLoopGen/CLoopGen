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
    if (len > 1) {
        output[1] = input[1] + input[3];
        for (i = 2; i < len; i++) {
            output[i] = output[i-1] + (input[2 * i - 1] - input[2 * i - 3]) + (input[2 * i + 1] - input[2 * i - 1]);
        }
    }
}
