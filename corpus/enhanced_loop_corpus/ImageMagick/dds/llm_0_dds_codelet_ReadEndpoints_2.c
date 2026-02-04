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
extern unsigned char alpha_bits;
extern unsigned char color_bits;
extern size_t num_subsets;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < num_subsets; outer++) {
        for (size_t inner = 0; inner < 2; inner++) {
            size_t i = outer * 2 + inner;
            endpoints->r[i] <<= (8 - color_bits);
            endpoints->g[i] <<= (8 - color_bits);
            endpoints->b[i] <<= (8 - color_bits);
            endpoints->a[i] <<= (8 - alpha_bits);
            endpoints->r[i] = endpoints->r[i] | (endpoints->r[i] >> color_bits);
            endpoints->g[i] = endpoints->g[i] | (endpoints->g[i] >> color_bits);
            endpoints->b[i] = endpoints->b[i] | (endpoints->b[i] >> color_bits);
            endpoints->a[i] = endpoints->a[i] | (endpoints->a[i] >> alpha_bits);
        }
    }
}
