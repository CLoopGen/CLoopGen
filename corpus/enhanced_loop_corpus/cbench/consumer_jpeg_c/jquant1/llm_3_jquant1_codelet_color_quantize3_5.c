#include <stdio.h>

#include <inttypes.h>

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
    JSAMPROW idx0 = colorindex0;
    JSAMPROW idx1 = colorindex1;
    JSAMPROW idx2 = colorindex2;
    for (col = width; col > 0; col--) {
        int val0 = *ptrin++;
        int val1 = *ptrin++;
        int val2 = *ptrin++;
        pixcode = ((int)(idx0[val0])) + ((int)(idx1[val1])) + ((int)(idx2[val2]));
        *ptrout++ = (JSAMPLE)pixcode;
    }
}
}
