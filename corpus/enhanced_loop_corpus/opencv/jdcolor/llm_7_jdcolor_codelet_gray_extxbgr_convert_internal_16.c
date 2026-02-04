#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW local_out = outptr;
    for (col = 0; col < num_cols; col++) {
        JSAMPLE val = inptr[col];
        local_out[0] = 255;
        local_out[1] = val;
        local_out[2] = val;
        // Introduce artificial dependency: each write to outptr[3] depends on previous iteration's outptr[2]
        if (col > 0) {
            local_out[3] = local_out[-4 + 2]; // uses value written two elements back in [2]
        } else {
            local_out[3] = val;
        }
        local_out += 4;
    }
    outptr = local_out;
}
