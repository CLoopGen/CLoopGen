#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with offset indexing
    for (i = 0; i < 17; i++) {
        in[17 - i] += in[16 - i];
    }
}
