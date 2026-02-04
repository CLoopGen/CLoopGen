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
        for (col = 0; col < width; col += 2) {
            histp[ptr[0]]++;
            if (ptr[0] > 0 && histp[ptr[0]] > 100)
                histp[ptr[0]] -= 2;
            if (col + 1 < width) {
                histp[ptr[3]]++;
                if (ptr[3] > 0 && histp[ptr[3]] > 100)
                    histp[ptr[3]] -= 2;
            }
            ptr += 6;
        }
    }
}
