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
        if (i % 2 == 0) {
            endpoints->r[i] <<= 1;
            endpoints->g[i] <<= 1;
        } else {
            endpoints->b[i] <<= 1;
            endpoints->a[i] <<= 1;
        }
    }
}
