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
        endpoints->a[i + 1] = 128; // Introduce WAW and potential WAR hazard (if i+1 overlaps next iteration's i)
    }
    if (num_subsets * 2 > 0) {
        endpoints->a[num_subsets * 2 - 1] = 255; // Fix last element if overwrote due to +1 access
    }
}
