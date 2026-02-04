#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

extern JSAMPARRAY input_buf;
extern JSAMPARRAY output_buf;
extern int num_rows;
extern JSAMPARRAY colorindex;
extern int pixcode;
extern int ci;
extern JSAMPROW ptrin;
extern JSAMPROW ptrout;
extern int row;
extern JDIMENSION col;
extern JDIMENSION width;
extern int nc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 0; row < num_rows; row++) {
        ptrin = input_buf[row];
        ptrout = output_buf[row];
        // Eliminate loop-carried dependency on ptrin and ptrout by using indexed access
        for (col = 0; col < width; col++) { // Change direction: now forward iteration
            pixcode = 0;
            // Unroll the inner loop partially to modify WAW dependencies
            int remainder = nc % 2;
            int limit = nc - remainder;
            for (ci = 0; ci < limit; ci += 2) {
                pixcode += colorindex[ci][ptrin[col]] + colorindex[ci+1][ptrin[col]];
            }
            if (remainder) {
                pixcode += colorindex[nc - 1][ptrin[col]];
            }
            ptrout[col] = (JSAMPLE)pixcode; // Write directly via index, no pointer carry
        }
    }
}
