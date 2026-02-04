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
        for (int offset = 0; offset < 2 && (row + offset) < num_rows; offset++) {
            int curr_row = row + offset;
            ptr = image_data[curr_row] + input_cols;
            pixval = ptr[-1];
            for (count = numcols; count > 0; count--) {
                *ptr++ = pixval;
            }
        }
    }
}
