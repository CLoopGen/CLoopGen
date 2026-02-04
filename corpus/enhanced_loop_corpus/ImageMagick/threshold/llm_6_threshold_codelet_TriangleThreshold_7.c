#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern ssize_t i;
extern ssize_t end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t temp_end = -1;
    for (i = (ssize_t)255; i >= 0; i--) {
        double val = histogram[i];
        if (val > 0.) {
            temp_end = i;  // Introduce temporary variable to remove direct WAW on 'end'
        }
    }
    end = temp_end;  // Write to 'end' only once after loop (eliminates loop-carried WAW dependency)
}
