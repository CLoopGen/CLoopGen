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
    // Variant 2: Reverse sequential memory access
    for (i = length - 1; i >= 0; i--) {
        absolute = ((vector[i]) >= 0 ? (vector[i]) : (-(vector[i])));
        if (absolute > maximum)
            maximum = absolute;
    }
}
