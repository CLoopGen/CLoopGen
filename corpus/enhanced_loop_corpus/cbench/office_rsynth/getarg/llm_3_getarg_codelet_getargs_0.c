#include <stdio.h>

#include <inttypes.h>

extern int j;
extern int argc;
extern char *argv[];
extern int i;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access
    // Process elements in strides of 2 to create a non-unit stride access pattern
    int stride = 2;
    for (j = i; j <= argc; j += stride)
        argv[j] = argv[j + off];
}
