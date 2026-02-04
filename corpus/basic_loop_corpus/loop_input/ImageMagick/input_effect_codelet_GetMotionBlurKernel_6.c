#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double MagickDoubleType;
typedef MagickDoubleType MagickRealType;

size_t width;
MagickRealType *kernel;
MagickRealType normalize;
ssize_t i;

void init_vars() {
    width = 16777216; // 16M elements -> ~128MB of data (16M * 8 bytes per double)
    kernel = (MagickRealType *)aligned_alloc(32, width * sizeof(MagickRealType));
    if (!kernel) {
        exit(1);
    }
    for (size_t idx = 0; idx < width; idx++) {
        kernel[idx] = (MagickRealType)(idx + 1);
    }
    normalize = 123.456;
    i = 0;
}