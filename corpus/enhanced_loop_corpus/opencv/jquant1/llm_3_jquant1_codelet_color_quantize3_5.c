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
        JSAMPROW cin0 = colorindex0;
        JSAMPROW cin1 = colorindex1;
        JSAMPROW cin2 = colorindex2;
        for (col = width; col > 0; col--) {
            pixcode = *(cin0 + *(ptrin + 0));
            pixcode += *(cin1 + *(ptrin + 1));
            pixcode += *(cin2 + *(ptrin + 2));
            *ptrout = (JSAMPLE)pixcode;
            ptrin += 3;
            ptrout++;
        }
    }
}
