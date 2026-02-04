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
    for (i = 0; i < num_subsets; i++) {
        size_t idx = i * 2;
        endpoints->r[idx] <<= 2;
        endpoints->g[idx] <<= 2;
        endpoints->b[idx] <<= 2;
        endpoints->a[idx] <<= 2;
        endpoints->r[idx + 1] <<= 2;
        endpoints->g[idx + 1] <<= 2;
        endpoints->b[idx + 1] <<= 2;
        endpoints->a[idx + 1] <<= 2;
    }
}
