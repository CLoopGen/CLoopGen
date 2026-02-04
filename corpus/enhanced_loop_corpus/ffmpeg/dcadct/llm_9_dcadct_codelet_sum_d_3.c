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
    for (i = 1; i < len; i++) {
        int idx1 = 2 * i - 1;
        int idx2 = 2 * i + 1;
        if (idx1 >= 0 && idx2 < 2 * len) {
            output[i] = (input[idx1] + input[idx2]) * 2;
        }
    }
}
