#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int16_t *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index remapping (reverse order traversal)
    for (i = 0; i < len; i++) {
        int idx = len - 1 - i;  // Reverse access pattern
        unsigned int a = in[0][idx];
        int b = in[1][idx];
        a -= b >> 1;
        (*samples++) = (a + b) << shift;
        (*samples++) = a << shift;
    }
}
