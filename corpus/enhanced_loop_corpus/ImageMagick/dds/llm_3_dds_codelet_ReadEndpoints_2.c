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
    // Variant 2: Strided access with reversed order and stride of 2
    size_t total_elements = num_subsets * 2;
    size_t stride = 2;
    size_t offset = (total_elements % stride);

    // Process elements in reverse, strided manner: start from last possible index in each stride group
    for (i = 0; i < total_elements; i++) {
        size_t idx = total_elements - 1 - i;  // Reverse iteration index

        if (idx >= 6) continue;  // Skip out-of-bounds since BC7Colors arrays are fixed size 6

        endpoints->r[idx] <<= (8 - color_bits);
        endpoints->g[idx] <<= (8 - color_bits);
        endpoints->b[idx] <<= (8 - color_bits);
        endpoints->a[idx] <<= (8 - alpha_bits);

        endpoints->r[idx] |= (endpoints->r[idx] >> color_bits);
        endpoints->g[idx] |= (endpoints->g[idx] >> color_bits);
        endpoints->b[idx] |= (endpoints->b[idx] >> color_bits);
        endpoints->a[idx] |= (endpoints->a[idx] >> alpha_bits);
    }
}
