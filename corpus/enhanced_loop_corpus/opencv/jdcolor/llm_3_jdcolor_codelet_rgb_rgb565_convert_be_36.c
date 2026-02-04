#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JLONG rgb;
extern unsigned int r;
extern unsigned int g;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW p0 = inptr0;
    JSAMPROW p1 = inptr1;
    JSAMPROW p2 = inptr2;
    JSAMPROW out = outptr;
    for (col = 0; col < (num_cols >> 1); col++) {
        r = *(p0++);
        g = *(p1++);
        b = *(p2++);
        rgb = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
        r = *(p0++);
        g = *(p1++);
        b = *(p2++);
        rgb = ((rgb << 16) | (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936)));
        *(int*)out = rgb;
        out += 4;
    }
    outptr = out;
}
