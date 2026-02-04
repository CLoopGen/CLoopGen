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
            int val0 = ((int)(colorindex0[((int)(*ptrin++))]));
            int val1 = ((int)(colorindex1[((int)(*ptrin++))]));
            int val2 = ((int)(colorindex2[((int)(*ptrin++))]));
            *ptrout++ = (JSAMPLE)((val0 + val1 + val2) / 3);
        }
        if (row + 1 < num_rows) {
            ptrin = input_buf[row + 1];
            ptrout = output_buf[row + 1];
            for (col = width; col > 0; col--) {
                pixcode = ((int)(colorindex0[((int)(*ptrin++))])) +
                          ((int)(colorindex1[((int)(*ptrin++))])) +
                          ((int)(colorindex2[((int)(*ptrin++))]));
                *ptrout++ = (JSAMPLE)pixcode;
            }
        }
    }
}
