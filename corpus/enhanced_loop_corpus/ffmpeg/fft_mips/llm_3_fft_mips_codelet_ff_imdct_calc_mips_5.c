#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via offset array
    // Simulate a strided and indirect-like access pattern using precomputed index offsets
    int strides[8];
    for (k = 0; k < n4; k += 4) {
        // Precompute indirect offsets to create a non-unit stride access pattern
        strides[0] = k;
        strides[1] = k + 1;
        strides[2] = k + 2;
        strides[3] = k + 3;
        strides[4] = n - k - 1;
        strides[5] = n - k - 2;
        strides[6] = n - k - 3;
        strides[7] = n - k - 4;

        // Use the offset table to access memory in a less predictable, strided manner
        output[strides[0]] = -output[n2 - k - 1];
        output[strides[1]] = -output[n2 - k - 2];
        output[strides[2]] = -output[n2 - k - 3];
        output[strides[3]] = -output[n2 - k - 4];
        output[strides[4]] = output[n2 + k];
        output[strides[5]] = output[n2 + k + 1];
        output[strides[6]] = output[n2 + k + 2];
        output[strides[7]] = output[n2 + k + 3];
    }
}
