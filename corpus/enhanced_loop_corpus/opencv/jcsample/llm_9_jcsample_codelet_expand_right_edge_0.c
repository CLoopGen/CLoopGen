#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

extern JSAMPARRAY image_data;
extern int num_rows;
extern JDIMENSION input_cols;
extern JSAMPROW ptr;
extern JSAMPLE pixval;
extern int count;
extern int row;
extern int numcols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 0; row < num_rows; row += 2) {
        JSAMPROW ptr1, ptr2;
        JSAMPLE pixval1, pixval2;
        if (row < num_rows) {
            ptr1 = image_data[row] + input_cols;
            pixval1 = ptr1[-1];
            for (count = numcols; count > 0; count--) {
                *ptr1++ = pixval1;
            }
        }
        if (row + 1 < num_rows) {
            ptr2 = image_data[row + 1] + input_cols;
            pixval2 = ptr2[-1];
            for (count = numcols; count > 0; count--) {
                *ptr2++ = pixval2;
            }
        }
    }
}
