#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double MagickDoubleType;

typedef MagickDoubleType MagickRealType;

extern MagickRealType t;
extern MagickRealType *k;
extern ssize_t i;
extern ssize_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < j && k != NULL; i++ , j--) {
    if (i >= 0 && j > i) {
        t = k[i];
        k[i] = k[j];
        k[j] = t;
    }
}
}
