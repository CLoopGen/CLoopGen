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
for (row = 0; row < num_rows; row += 2) {
    ptrin = input_buf[row];
    ptrout = output_buf[row];
    for (col = width; col > 0; col--) {
        pixcode = ((int)(colorindex0[((int)(*ptrin++))]));
        pixcode += ((int)(colorindex1[((int)(*ptrin++))]));
        pixcode += ((int)(colorindex2[((int)(*ptrin++))]));
        *ptrout++ = (JSAMPLE)pixcode;
    }
    if (row + 1 < num_rows) {
        ptrin = input_buf[row + 1];
        ptrout = output_buf[row + 1];
        for (col = width / 2; col > 0; col--) {
            pixcode = ((int)(colorindex0[((int)(*ptrin++))]));
            pixcode += ((int)(colorindex1[((int)(*ptrin++))]));
            pixcode += ((int)(colorindex2[((int)(*ptrin++))]));
            *ptrout++ = (JSAMPLE)pixcode;
        }
    }
}
}
