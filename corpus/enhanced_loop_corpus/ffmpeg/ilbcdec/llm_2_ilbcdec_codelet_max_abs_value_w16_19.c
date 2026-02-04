#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *vector;
extern int length;
extern int i;
extern int absolute;
extern int maximum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < length; i += 2) {
        absolute = ((vector[i]) >= 0 ? (vector[i]) : (-(vector[i])));
        if (absolute > maximum)
            maximum = absolute;
    }
}
