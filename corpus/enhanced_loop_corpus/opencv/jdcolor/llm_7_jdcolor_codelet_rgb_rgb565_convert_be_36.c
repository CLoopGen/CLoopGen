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
    JLONG temp_rgb[2];
    for (col = 0; col < (num_cols >> 1); col++) {
        temp_rgb[0] = 0;
        temp_rgb[1] = 0;
        r = inptr0[col * 2];
        g = inptr1[col * 2];
        b = inptr2[col * 2];
        temp_rgb[0] = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
        r = inptr0[col * 2 + 1];
        g = inptr1[col * 2 + 1];
        b = inptr2[col * 2 + 1];
        temp_rgb[1] = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
        rgb = (temp_rgb[0]) | ((temp_rgb[1]) << 16);
        ((*(int *)(outptr + (col << 2))) = rgb);
    }
}
