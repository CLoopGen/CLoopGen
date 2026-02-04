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
    for (i = 1; i < len && i < 1000; i++) {
        int idx1 = 2 * i;
        int idx2 = 2 * i - 1;
        int val1 = input[idx1];
        int val2 = input[idx2];
        output[i] = val1 + val2 + (val1 > val2 ? 1 : -1);
    }
}
