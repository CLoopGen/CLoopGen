#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int32_t *out;
extern  int32_t *in;
extern integer len;
extern int i;
extern int64_t coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (processing array from end to start)
    for (i = len - 1; i >= 0; i--) {
        out[i] = (((coeff * in[i]) + 16384) >> 15);
    }
}
