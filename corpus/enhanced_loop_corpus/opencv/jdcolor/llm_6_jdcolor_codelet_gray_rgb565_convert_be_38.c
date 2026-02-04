#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JLONG rgb;
extern unsigned int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION col_shifted;
    for (col = 0; col < (num_cols >> 1); col++) {
        col_shifted = col << 1;
        g = inptr[col_shifted];
        rgb = (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936));
        g = inptr[col_shifted + 1];
        rgb |= ((uint64_t)(((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936))) << 16;
        ((*(int *)(outptr + (col << 2))) = rgb);
    }
}
