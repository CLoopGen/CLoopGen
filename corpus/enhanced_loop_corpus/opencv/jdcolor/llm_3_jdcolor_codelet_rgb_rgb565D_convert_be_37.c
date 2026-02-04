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
extern JSAMPLE *range_limit;
extern JDIMENSION num_cols;
extern JLONG d0;
extern JLONG rgb;
extern unsigned int r;
extern unsigned int g;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal and stride of 2
    JDIMENSION stride = 2;
    JDIMENSION max_col = (num_cols >> 1) - 1;

    JSAMPROW in0_base = inptr0 - 2; // Adjust base for reverse indexing
    JSAMPROW in1_base = inptr1 - 2;
    JSAMPROW in2_base = inptr2 - 2;
    JSAMPROW out_base = outptr - 4;

    JLONG d_temp = d0;

    for (col = max_col; col != (JDIMENSION)(-1); col--) {
        // Access elements with negative stride (reverse order)
        r = range_limit[(in0_base[(max_col - col + 1) * stride] + (d_temp & 255))];
        g = range_limit[(in1_base[(max_col - col + 1) * stride] + ((d_temp & 255) >> 1))];
        b = range_limit[(in2_base[(max_col - col + 1) * stride] + (d_temp & 255))];

        d_temp = (((d_temp & 255) << 24) | ((d_temp >> 8) & 16777215));

        rgb = ((r & 248) | (g >> 5) | ((g << 11) & 57344) | ((b << 5) & 7936));

        r = range_limit[(in0_base[(max_col - col + 1) * stride - 1] + (d_temp & 255))];
        g = range_limit[(in1_base[(max_col - col + 1) * stride - 1] + ((d_temp & 255) >> 1))];
        b = range_limit[(in2_base[(max_col - col + 1) * stride - 1] + (d_temp & 255))];

        d_temp = (((d_temp & 255) << 24) | ((d_temp >> 8) & 16777215));

        rgb = (rgb << 16) | ((r & 248) | (g >> 5) | ((g << 11) & 57344) | ((b << 5) & 7936));

        ((*(int *)(out_base + ((max_col - col + 1) << 2))) = rgb);
    }

    // Update globals to reflect advancement
    inptr0 += num_cols;
    inptr1 += num_cols;
    inptr2 += num_cols;
    outptr += (num_cols << 1);
    d0 = d_temp;
}
