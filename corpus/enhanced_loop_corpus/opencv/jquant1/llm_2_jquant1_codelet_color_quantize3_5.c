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
extern int pixcode;
extern JSAMPROW ptrin;
extern JSAMPROW ptrout;
extern JSAMPROW colorindex0;
extern JSAMPROW colorindex1;
extern JSAMPROW colorindex2;
extern int row;
extern JDIMENSION col;
extern JDIMENSION width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 0; row < num_rows; row++) {
        ptrin = input_buf[row];
        ptrout = output_buf[row];
        JDIMENSION col = 0;
        for (; col < width; col++) {
            int idx = col * 3;
            pixcode = colorindex0[ptrin[idx]];
            pixcode += colorindex1[ptrin[idx + 1]];
            pixcode += colorindex2[ptrin[idx + 2]];
            ptrout[col] = (JSAMPLE)pixcode;
        }
    }
}
