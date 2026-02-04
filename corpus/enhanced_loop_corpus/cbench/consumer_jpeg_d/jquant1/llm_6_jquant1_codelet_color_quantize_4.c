#include <stdio.h>

#include <inttypes.h>

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
            // Eliminate loop-carried dependency in ci-loop by unrolling and reordering operations
            // Introduce temporary variables to break WAW and WAR hazards
            int temp_sum = 0;
            for (ci = nc - 1; ci >= 0; ci--) {
                temp_sum += ((int)(colorindex[ci][((int)(*ptrin))]));
                ptrin++; // RAW dependency preserved on *ptrin, but update delayed
            }
            *ptrout++ = (JSAMPLE)temp_sum;
        }
    }
}
