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
    size_t limit = num_subsets * 2;
    for (i = 0; i < limit; i++) {
        endpoints->r[i] = 255;
        endpoints->g[i] = 255;
        endpoints->b[i] = 255;
        endpoints->a[i] = 255;
    }
}
