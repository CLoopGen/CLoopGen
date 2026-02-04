#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *in;
extern int len;
extern int i;
extern int32_t max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len + 4; i += 2) {
        if (i < len + 4) {
            max |= ((in[i]) >= 0 ? (in[i]) : (-(in[i])));
        }
    }
}
