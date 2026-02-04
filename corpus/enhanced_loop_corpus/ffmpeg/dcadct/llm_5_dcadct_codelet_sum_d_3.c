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
        int index_prev = 2 * i - 1;
        int index_next = 2 * i + 1;
        if (index_prev >= 0) {
            output[i] = input[index_prev];
            if (index_next < 2 * len) {
                output[i] += input[index_next];
            }
        } else {
            output[i] = 0;
        }
    }
}
