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
        for (col = width; col > 0; col--) {
            pixcode = 0;
            // Introduce temporary array to remove direct RAW dependency on ptrin increment
            JSAMPLE temp_vals[4] = {0}; // Assume nc <= 4 for safety
            for (ci = 0; ci < nc; ci++) {
                temp_vals[ci] = *ptrin++; // Load all inputs first
            }
            for (ci = 0; ci < nc; ci++) {
                pixcode += colorindex[ci][temp_vals[ci]]; // Then process them
            }
            *ptrout++ = (JSAMPLE)pixcode;
        }
    }
}
