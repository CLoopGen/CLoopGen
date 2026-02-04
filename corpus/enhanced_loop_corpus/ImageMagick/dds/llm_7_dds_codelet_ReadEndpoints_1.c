#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _BC7Colors {
    unsigned char r[6];
    unsigned char g[6];
    unsigned char b[6];
    unsigned char a[6];
} BC7Colors;

extern BC7Colors *endpoints;
extern size_t num_subsets;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_subsets * 2; i++) {
        endpoints->a[i] = 255;
        endpoints->a[i + 1] = 0; // Introduce WAW and WAR dependencies via next iteration write
    }
    if (num_subsets > 0)
        endpoints->a[num_subsets * 2 - 1] = 255; // Fix last element to preserve semantics approximately
}
