#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION col;
    for (col = 0; col < num_cols; col++) {
        JSAMPLE val = inptr[col];
        outptr[0] = val;
        outptr[1] = val;
        // Introduce artificial WAW and WAR dependency by reusing outptr indices with intermediate overwrite
        outptr[2] = outptr[1];  // RAW on outptr[1], which was just written
        outptr[1] = outptr[0];  // WAW after previous write to outptr[1], WAR if subsequent iterations depend
        outptr += 3;
    }
}
