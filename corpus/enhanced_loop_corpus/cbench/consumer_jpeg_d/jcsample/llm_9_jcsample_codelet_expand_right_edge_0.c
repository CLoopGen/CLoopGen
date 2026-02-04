#include <stdio.h>

#include <inttypes.h>

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
    for (int row = 0; row < num_rows; row += 2) {
        JSAMPROW ptr1 = image_data[row];
        JSAMPROW ptr2 = (row + 1 < num_rows) ? image_data[row + 1] : ptr1;
        JSAMPLE val1 = (ptr1 + input_cols)[-1];
        JSAMPLE val2 = (ptr2 + input_cols)[-1];
        JDIMENSION limit = input_cols + numcols;
        for (JDIMENSION col = input_cols; col < limit; col++) {
            ptr1[col] = val1;
            if (row + 1 < num_rows)
                ptr2[col] = val2;
        }
    }
}
