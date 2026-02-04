#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double MagickDoubleType;

typedef MagickDoubleType MagickRealType;

extern  size_t width;
extern MagickRealType *kernel;
extern MagickRealType normalize;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t outer = 0; outer < (ssize_t)width; outer++) {
        i = outer;
        for (ssize_t inner = 0; inner < 1; inner++)
            kernel[i] /= normalize;
    }
}
