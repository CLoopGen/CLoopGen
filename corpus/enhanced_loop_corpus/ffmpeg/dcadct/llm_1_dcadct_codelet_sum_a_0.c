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
    int inner_len = len / 2;
    if (len % 2 != 0) inner_len++;
    for (i = 0; i < inner_len; i++) {
        int idx = 2 * i;
        if (idx < len * 2 - 1) {
            if (idx < len * 2 - 1) output[i] = input[idx] + input[idx + 1];
        }
    }
}
