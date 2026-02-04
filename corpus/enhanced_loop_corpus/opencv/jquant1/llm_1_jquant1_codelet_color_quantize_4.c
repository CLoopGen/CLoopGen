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
    for (col = 0; col < width; col++) {
        pixcode = 0;
        for (ci = 0; ci < nc; ci++) {
            pixcode += colorindex[ci][input_buf[row][col]];
        }
        output_buf[row][col] = (JSAMPLE)pixcode;
    }
}
}
