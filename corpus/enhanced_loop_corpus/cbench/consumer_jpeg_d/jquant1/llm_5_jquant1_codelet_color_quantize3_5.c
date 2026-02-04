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
    for (col = width; col > 0; col--) {
        pixcode = 0;
        int val0 = (int)(*ptrin++);
        int val1 = (int)(*ptrin++);
        int val2 = (int)(*ptrin++);
        pixcode += (int)(colorindex0[val0]);
        pixcode += (int)(colorindex1[val1]);
        if (val2 >= 0) {
            pixcode += (int)(colorindex2[val2]);
        }
        *ptrout++ = (JSAMPLE)pixcode;
    }
}
}
