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
        int index;
        for (ci = 0; ci < nc; ci++) {
            index = (int)(*ptrin);
            if (index >= 0) {
                pixcode += ((int)(colorindex[ci][index]));
            }
            ptrin++;
        }
        *ptrout++ = (JSAMPLE)pixcode;
    }
}
}
