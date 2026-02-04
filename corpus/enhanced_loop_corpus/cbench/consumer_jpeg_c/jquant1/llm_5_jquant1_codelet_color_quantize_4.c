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
        int skip_computation = 0;
        for (ci = 0; ci < nc; ci++) {
            int index_val = (int)(*ptrin);
            if (index_val < 0 || index_val > 255) {
                skip_computation = 1;
                ptrin++;
                break;
            }
            pixcode += ((int)(colorindex[ci][index_val]));
            ptrin++;
        }
        if (!skip_computation) {
            *ptrout++ = (JSAMPLE)pixcode;
        } else {
            *ptrout++ = 0;
        }
    }
}
}
