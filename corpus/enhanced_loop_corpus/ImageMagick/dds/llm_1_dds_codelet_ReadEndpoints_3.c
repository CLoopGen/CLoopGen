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
        for (size_t block = 0; block < num_subsets; block++) {
            size_t idx = block * 2;
            endpoints->r[idx] <<= 1;
            endpoints->g[idx] <<= 1;
            endpoints->b[idx] <<= 1;
            endpoints->a[idx] <<= 1;

            endpoints->r[idx + 1] <<= 1;
            endpoints->g[idx + 1] <<= 1;
            endpoints->b[idx + 1] <<= 1;
            endpoints->a[idx + 1] <<= 1;
        }
    }
}
