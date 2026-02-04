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
    JSAMPARRAY local_image_data = image_data;
    JDIMENSION local_cols = input_cols;
    int local_numcols = numcols;
    JSAMPLE prev_val;
    for (row = 0; row < num_rows; row++) {
        ptr = local_image_data[row] + local_cols;
        prev_val = ptr[-1];
        for (count = local_numcols; count > 0; count--) {
            ptr[count - 1] = prev_val;
        }
    }
}
