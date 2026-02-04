#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned short UINT16;

typedef UINT16 histcell;

typedef histcell *histptr;

typedef unsigned int JDIMENSION;

extern JSAMPARRAY input_buf;
extern int num_rows;
extern JSAMPROW ptr;
extern histptr histp;
extern int row;
extern JDIMENSION col;
extern JDIMENSION width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 0; row < num_rows; row++) {
        ptr = input_buf[row];
        for (col = 0; col < width; col++) {
            JSAMPLE val = ptr[col * 3];
            histptr update_ptr = histp + val;
            UINT16 old_val = (*update_ptr);
            (*update_ptr) = (old_val <= 0xFFFF - 2) ? old_val + 1 : old_val;
            if ((*update_ptr) == 0)
                (*update_ptr)--;
        }
    }
}
