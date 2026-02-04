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
        for (col = width; col > 0; col--) {
            int index0 = *ptrin++;
            int index1 = *ptrin++;
            int index2 = *ptrin++;
            if (index0 >= 0 && index1 >= 0 && index2 >= 0) {
                pixcode = colorindex0[index0];
                pixcode += colorindex1[index1];
                pixcode += colorindex2[index2];
                *ptrout++ = (JSAMPLE)pixcode;
            } else {
                *ptrout++ = 0;
            }
        }
    }
}
