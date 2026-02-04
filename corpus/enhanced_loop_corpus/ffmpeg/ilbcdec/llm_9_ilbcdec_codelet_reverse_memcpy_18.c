#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int16_t *destPtr;
extern int16_t *sourcePtr;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 1;
    for (j = 0; j < length; j++) {
        *destPtr-- = (*sourcePtr++ + *(sourcePtr - 1)) / stride; // Increased arithmetic intensity
        stride ^= 1; // Toggle between 1 and 0, but avoids division by zero since it starts at 1 and alternates
    }
}
