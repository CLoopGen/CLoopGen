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
    if (len <= 1) return;
    for (i = 1; i < len; i++) {
        int idx = 2 * i;
        output[i] = input[idx] + input[idx - 1];
    }
}
