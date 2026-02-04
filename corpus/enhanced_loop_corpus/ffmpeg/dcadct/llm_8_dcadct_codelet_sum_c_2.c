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
    for (i = 0; i < len; i += 2) {
        if (2 * i < len * 2) {
            output[i] = input[2 * i];
        }
        if (i + 1 < len && 2 * (i + 1) < len * 2) {
            output[i + 1] = input[2 * (i + 1)];
        }
    }
}
