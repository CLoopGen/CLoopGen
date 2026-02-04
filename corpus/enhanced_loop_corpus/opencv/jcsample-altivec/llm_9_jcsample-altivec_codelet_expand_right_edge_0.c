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
        JSAMPROW ptr1 = image_data[row];
        JSAMPROW ptr2 = (row + 1 < num_rows) ? image_data[row + 1] : ptr1;
        JDIMENSION limit = input_cols - (input_cols % 4);
        for (count = 0; count < limit; count += 4) {
            pixval = ptr1[count];
            ptr1[count + 1] = pixval;
            ptr1[count + 2] = pixval;
            ptr1[count + 3] = pixval;
            if (row + 1 < num_rows) {
                ptr2[count] = pixval;
                ptr2[count + 1] = pixval;
                ptr2[count + 2] = pixval;
                ptr2[count + 3] = pixval;
            }
        }
        for (; count < input_cols; count++) {
            if (row + 1 < num_rows) {
                image_data[row + 1][count] = ptr1[count];
            }
        }
    }
}
