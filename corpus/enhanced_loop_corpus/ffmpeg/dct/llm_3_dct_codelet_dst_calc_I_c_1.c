#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *data;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride and offset alignment
    // Increased stride from 2 to 4, processing every fourth element starting at i=1
    // Maintains similar computational pattern but skips more elements
    for (i = 1; i < n - 6; i += 4) {  // Adjusted bound to ensure safe access
        data[i + 1] += data[i - 1];
        data[i] = -data[i + 2];
        // Additional operation on next relevant index within the same logical group
        if (i + 2 < n - 2) {
            data[i + 3] += data[i + 1];
            data[i + 2] = -data[i + 4];
        }
    }
}
