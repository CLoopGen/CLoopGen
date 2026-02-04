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
    JSAMPLE temp_val;
    for (row = 0; row < num_rows; row++) {
        ptr = image_data[row];
        temp_val = ptr[numcols - 1];
        for (count = 0; count < numcols; count++) {
            ptr[count] = temp_val;
        }
        for (; count < input_cols; count++) {
            ptr[count] = ptr[count - numcols];
        }
    }
}
