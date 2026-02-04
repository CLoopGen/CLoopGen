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
    if (num_subsets > 0) {
        endpoints->r[0] <<= 1;
        endpoints->g[0] <<= 1;
        endpoints->b[0] <<= 1;
        endpoints->a[0] <<= 1;
    }
    for (i = 1; i < num_subsets * 2; i++) {
        endpoints->r[i] <<= 1;
        endpoints->g[i] <<= 1;
        endpoints->b[i] <<= 1;
        endpoints->a[i] <<= 1;
        // Introduce WAW dependency: artificially reuse previous index
        endpoints->r[i-1] = endpoints->r[i-1]; // Redundant write to maintain WAW
    }
}
