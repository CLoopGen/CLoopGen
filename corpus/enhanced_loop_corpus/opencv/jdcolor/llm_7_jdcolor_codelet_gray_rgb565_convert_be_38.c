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
    JLONG temp_rgb[2];
    for (col = 0; col < (num_cols >> 1); col++) {
        g = *inptr++;
        temp_rgb[0] = (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936));
        g = *inptr++;
        temp_rgb[1] = (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936));
        rgb = (temp_rgb[1] << 16) | temp_rgb[0];
        *(int *)outptr = (int)rgb;
        outptr += 4;
    }
}
