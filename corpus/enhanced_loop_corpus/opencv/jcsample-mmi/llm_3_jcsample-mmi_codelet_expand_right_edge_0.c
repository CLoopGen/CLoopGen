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
    JSAMPARRAY data = image_data;
    JDIMENSION cols = input_cols;
    for (int r = 0; r < num_rows; r += 2) {
        JSAMPROW ptr1 = data[r] + cols;
        JSAMPROW ptr2 = (r + 1 < num_rows) ? data[r + 1] + cols : NULL;
        JSAMPLE val1 = ptr1[-1];
        JSAMPLE val2 = (ptr2 != NULL) ? ptr2[-1] : val1;
        for (int c = 0; c < numcols; c++) {
            *ptr1++ = val1;
            if (ptr2 != NULL) {
                *ptr2++ = val2;
            }
        }
    }
}
