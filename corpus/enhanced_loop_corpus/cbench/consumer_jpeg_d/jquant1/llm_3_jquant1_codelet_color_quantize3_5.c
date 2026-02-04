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
for (int row = 0; row < num_rows; row++) {
    ptrin = input_buf[row];
    ptrout = output_buf[row];
    JDIMENSION col = 0;
    JDIMENSION stride = 3;
    for (; col + 7 < width; col += 8) {
        for (int unroll = 0; unroll < 8; unroll++) {
            JDIMENSION base = (col + unroll) * stride;
            pixcode = ((int)(colorindex0[((int)(ptrin[base]))]));
            pixcode += ((int)(colorindex1[((int)(ptrin[base + 1]))]));
            pixcode += ((int)(colorindex2[((int)(ptrin[base + 2]))]));
            ptrout[col + unroll] = (JSAMPLE)pixcode;
        }
    }
    for (; col < width; col++) {
        JDIMENSION base = col * stride;
        pixcode = ((int)(colorindex0[((int)(ptrin[base]))]));
        pixcode += ((int)(colorindex1[((int)(ptrin[base + 1]))]));
        pixcode += ((int)(colorindex2[((int)(ptrin[base + 2]))]));
        ptrout[col] = (JSAMPLE)pixcode;
    }
}
}
