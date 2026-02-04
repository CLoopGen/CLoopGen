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
    for (col = 0; col < (num_cols >> 1); col++) {
        g = *inptr++;
        rgb = (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936));
        
        if (g != 0) {
            g = *inptr++;
            rgb = ((rgb << 16) | (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936)));
        } else {
            // Use a fallback color component if zero input
            rgb = ((rgb << 16) | 0x1F);
        }

        (*(int *)(outptr)) = rgb;
        outptr += 4;

        // Introduce early exit based on data property
        if ((rgb & 0xFFFF) == 0x1F) {
            break;
        }
    }
}
