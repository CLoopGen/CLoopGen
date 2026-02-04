#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *in1;
extern  uint8_t *in2;
extern uint8_t *out;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from end to start
    // Iterates backward through the arrays, maintaining same logical operation
    for (i = n - 1; i >= 0; i--) {
        out[i] = in1[i] ^ in2[i];
    }
}
