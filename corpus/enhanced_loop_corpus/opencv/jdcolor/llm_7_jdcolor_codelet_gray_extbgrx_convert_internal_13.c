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
    JSAMPLE prev = 0;
    for (col = 0; col < num_cols; col++) {
        JSAMPLE current = inptr[col];
        outptr[0] = current;
        outptr[1] = (col == 0) ? current : prev; // Introduce WAR dependency: write after read of prev
        outptr[2] = current;
        outptr[3] = 255;
        prev = current; // Create loop-carried dependency (WAW via 'prev')
        outptr += 4;
    }
}
