#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in1;
extern  int16_t *in2;
extern int length;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (backward traversal)
    for (int i = length - 1; i >= 0; i--) {
        out[i] = (in1[i] + in2[i]) >> shift;
    }
}
