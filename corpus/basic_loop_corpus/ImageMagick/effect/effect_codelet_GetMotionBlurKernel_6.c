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
for (i = 0; i < (ssize_t)width; i++)
    kernel[i] /= normalize;

}
