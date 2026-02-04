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
    for (int outer = 0; outer < num_rows; outer++) {
        ptr = image_data[outer] + input_cols;
        pixval = ptr[-1];
        for (int row = 0; row < 1; row++) {
            for (count = numcols; count > 0; count--)
                *ptr++ = pixval;
        }
    }
}
