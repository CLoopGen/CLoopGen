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
    if (num_rows > 0 && numcols > 0) {
        ptr = image_data[0] + input_cols;
        pixval = ptr[-1];
        for (int total = 0; total < num_rows * numcols; total++) {
            *ptr++ = pixval;
            if ((total + 1) % numcols == 0) {
                row = (total + 1) / numcols;
                if (row < num_rows) {
                    ptr = image_data[row] + input_cols;
                    pixval = ptr[-1];
                }
            }
        }
    }
}
