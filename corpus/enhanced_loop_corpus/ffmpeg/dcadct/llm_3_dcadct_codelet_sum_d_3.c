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
    // Variant 2: Strided Access with Index Scaling Separated
    // Explicitly separate stride calculation for clarity and potential vectorization
    // Uses scaled indices to emphasize regular striding by 2
    for (i = 1; i < len; i++) {
        int idx = i * 2;
        output[i] = input[idx - 1] + input[idx + 1];
    }
}
