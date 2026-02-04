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
    JSAMPROW cin0 = colorindex0;
    JSAMPROW cin1 = colorindex1;
    JSAMPROW cin2 = colorindex2;
    for (JDIMENSION col = 0; col < width; col++) {
        int idx = col * 3;
        pixcode = ((int)(cin0[((int)(ptrin[idx]))]));
        pixcode += ((int)(cin1[((int)(ptrin[idx + 1]))]));
        pixcode += ((int)(cin2[((int)(ptrin[idx + 2]))]));
        ptrout[col] = (JSAMPLE)pixcode;
    }
}
}
